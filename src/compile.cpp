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

std::string special_char_map(char c) {
    auto result = std::string(1, c);
    switch (c) {
        case '\n':
            result = "\\n";
            break;
        case '\"':
            result = "\\\"";
            break;
        case '\\':
            result = "\\\\";
            break;
        case '\t':
            result = "\\t";
            break;
        case '\'':
            result = "\\'";
            break;
        case '\?':
            result = "\\?";
            break;
        case '\a':
            result = "\\a";
            break;
        case '\b':
            result = "\\b";
            break;
        case '\f':
            result = "\\f";
            break;
        case '\r':
            result = "\\r";
            break;
        case '\v':
            result = "\\v";
            break;
    }
    return result;
}

/// Insert '\' before special chars so they can be interpreted by Wandbox.
std::string shield_escaped(const std::string& input) {
    std::string result;
    for (char c : input) {
        result.append(special_char_map(c));
    }
    return result;
}
}  // namespace

namespace wandbox {

Result compile(const Session& context, const std::string& code) {
    auto request = http::generate::basic_POST_request(
        detail::host_k, "/api/compile.json", false);
    request.headers["Content-type"] = "application/json";
    request.message_body = detail::to_string(context, shield_escaped(code));

    http::send(request, detail::get_connection());
    auto response = http::read(detail::get_connection());
    auto ptree = http::parse::json_ptree(response.message_body);
    return detail::to_result(ptree);
}

}  // namespace wandbox
