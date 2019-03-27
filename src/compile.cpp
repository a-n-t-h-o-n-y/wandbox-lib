#include <wandbox/compile.hpp>

#include <string>

#include <http/generate/basic_post_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_result.hpp>
#include <wandbox/detail/to_string.hpp>
#include <wandbox/result.hpp>
#include <wandbox/session.hpp>

namespace {

/// Clean source code so that it can be sent along a socket.
std::string sanitize(const std::string& input) {
    std::string result;
    for (char c : input) {
        std::string to_put(1, c);
        if (c == '\n') {
            to_put = "\\n";
        } else if (c == '\t') {
            to_put = "\\t";
        } else if (c == '\"') {
            to_put = "\\\"";
        } else if (c == '\\') {
            to_put = "\\\\";
        }
        result.append(to_put);
    }
    return result;
}
}  // namespace

namespace wandbox {

Result compile(const Session& context, const std::string& code) {
    auto request = http::generate::basic_POST_request(
        detail::host_k, "/api/compile.json", false);
    request.headers["Content-type"] = "application/json";
    request.message_body = detail::to_string(context, sanitize(code));

    http::send(request, detail::get_connection());
    auto response = http::read(detail::get_connection());
    auto ptree = http::parse::json_ptree(response.message_body);
    return detail::to_result(ptree);
}

}  // namespace wandbox
