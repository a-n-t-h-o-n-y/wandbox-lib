#include <wandbox/get_template.hpp>

#include <string>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>

#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/send.hpp>

namespace wandbox {

std::string get_template(const std::string& name) {
    const auto request = http::generate::basic_GET_request(
        detail::host_k, "/api/template/" + name, false);
    const auto json_response = detail::send(request);
    return json_response.get("code", "");
}

}  // namespace wandbox
