#include <wandbox/compile.hpp>

#include <string>

#include <boost/asio.hpp>

#include <http/generate/basic_post_request.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/compiler.hpp>
#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_result.hpp>
#include <wandbox/detail/to_string.hpp>
#include <wandbox/result.hpp>

namespace wandbox {

Result compile(const Compiler& context, const std::string& code) {
    http::HTTP_request compile_request = http::generate::basic_POST_request(
        detail::host_k, "/api/compile.json", false);

    compile_request.headers["Content-type"] = "application/json";

    compile_request.message_body = detail::to_string(context, code);

    http::send(compile_request, detail::get_connection());

    http::HTTP_response compile_response{http::read(detail::get_connection())};
    auto ptree = http::parse::json_ptree(compile_response.message_body);
    return detail::to_result(ptree);
}

}  // namespace wandbox
