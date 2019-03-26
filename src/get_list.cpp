#include <wandbox/get_list.hpp>

#include <vector>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/compiler.hpp>
#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_compiler.hpp>
#include <wandbox/switch.hpp>

namespace wandbox {

std::vector<Compiler> get_list() {
    auto request = http::generate::basic_GET_request(detail::host_k,
                                                     "/api/list.json", false);
    http::send(request, detail::get_connection());
    auto response = http::read(detail::get_connection());
    auto ptree = http::parse::json_ptree(response.message_body);
    std::vector<Compiler> result;
    for (auto& child : ptree) {
        result.push_back(detail::to_compiler(child.second));
    }
    return result;
}

}  // namespace wandbox
