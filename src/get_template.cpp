#include <wandbox/get_template.hpp>

#include <string>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/detail/get_connection.hpp>

namespace wandbox {

std::string get_template(const std::string& name) {
    auto request = http::generate::basic_GET_request(
        detail::host_k, "/api/template/" + name, false);
    http::send(request, detail::get_connection());

    auto response = http::read(detail::get_connection());
    auto ptree = http::parse::json_ptree(response.message_body);

    return ptree.get("code", "");
}

}  // namespace wandbox
