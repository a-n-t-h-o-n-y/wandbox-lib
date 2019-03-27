#include <wandbox/compile.hpp>

#include <string>

#include <http/generate/basic_post_request.hpp>
#include <http/http_request.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/send.hpp>
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

/// Create a HTTP_request to compile \p code.
http::HTTP_request generate_compile_request(const wandbox::Session& context,
                                            const std::string& code) {
    using namespace wandbox;
    auto request = http::generate::basic_POST_request(
        detail::host_k, "/api/compile.json", false);
    request.headers["Content-type"] = "application/json";
    request.message_body = detail::to_string(context, shield_escaped(code));
    return request;
}

}  // namespace

namespace wandbox {

Result compile(const Session& context, const std::string& code) {
    const auto request = generate_compile_request(context, code);
    const auto json_result = detail::send(request);
    return detail::to_result(json_result);
}

}  // namespace wandbox
