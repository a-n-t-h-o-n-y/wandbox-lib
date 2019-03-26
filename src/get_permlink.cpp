#include <wandbox/get_permlink.hpp>

#include <iostream>  //temp
#include <string>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_compiler.hpp>
#include <wandbox/detail/to_result.hpp>
#include <wandbox/detail/to_string.hpp>  //temp
#include <wandbox/result.hpp>

namespace wandbox {

Permlink_result get_permlink(const std::string& permlink) {
    http::HTTP_request permlink_request = http::generate::basic_GET_request(
        detail::host_k, "/api/permlink/" + permlink, false);
    http::send(permlink_request, detail::get_connection());
    http::HTTP_response permlink_response{http::read(detail::get_connection())};

    auto ptree = http::parse::json_ptree(permlink_response.message_body);
    Result result = detail::to_result(ptree.get_child("result"));
    Compiler compiler = detail::to_compiler(ptree.get_child("parameter"));
    std::string code = ptree.get_child("parameter").get("code", "");
    return {result, compiler, code};
}

}  // namespace wandbox
