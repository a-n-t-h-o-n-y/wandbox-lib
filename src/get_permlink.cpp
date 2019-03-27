#include <wandbox/get_permlink.hpp>

#include <string>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/send.hpp>
#include <wandbox/detail/to_result.hpp>
#include <wandbox/detail/to_session.hpp>
#include <wandbox/result.hpp>

namespace wandbox {

Permlink_result get_permlink(const std::string& permlink) {
    const auto request = http::generate::basic_GET_request(
        detail::host_k, "/api/permlink/" + permlink, false);
    const auto json_result = detail::send(request);
    const auto result = detail::to_result(json_result.get_child("result"));
    const auto compiler =
        detail::to_session(json_result.get_child("parameter"));
    const auto code = json_result.get_child("parameter").get("code", "");
    return {result, compiler, code};
}

}  // namespace wandbox
