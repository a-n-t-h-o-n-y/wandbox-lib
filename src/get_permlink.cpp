#include <wandbox/get_permlink.hpp>

#include <string>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_result.hpp>
#include <wandbox/detail/to_session.hpp>
#include <wandbox/result.hpp>

namespace wandbox {

Permlink_result get_permlink(const std::string& permlink) {
    auto request = http::generate::basic_GET_request(
        detail::host_k, "/api/permlink/" + permlink, false);
    http::send(request, detail::get_connection());

    auto response = http::read(detail::get_connection());
    auto ptree = http::parse::json_ptree(response.message_body);

    const auto result = detail::to_result(ptree.get_child("result"));
    const auto compiler = detail::to_session(ptree.get_child("parameter"));
    const auto code = ptree.get_child("parameter").get("code", "");
    return {result, compiler, code};
}

}  // namespace wandbox
