#include <wandbox/get_list.hpp>

#include <iostream>  //temp
#include <vector>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/compiler_info.hpp>
#include <wandbox/detail/get_connection.hpp>
#include <wandbox/switch.hpp>

namespace wandbox {

std::vector<Compiler_info> get_list() {
    http::HTTP_request info_request = http::generate::basic_GET_request(
        detail::host_k, "/api/list.json", false);
    http::send(info_request, detail::get_connection());
    http::HTTP_response info_response{http::read(detail::get_connection())};
    auto ptree = http::parse::json_ptree(info_response.message_body);
    std::vector<Compiler_info> result;
    for (auto& thing : ptree) {
        Compiler_info temp;
        temp.name = thing.second.get("name", "");
        temp.display_name = thing.second.get("display-name", "");
        temp.version = thing.second.get("version", "");
        temp.language = thing.second.get("language", "");
        temp.display_compile_command =
            thing.second.get("display-compile-command", "");
        temp.compiler_option_raw =
            thing.second.get("compiler-option-raw", false);
        temp.runtime_option_raw = thing.second.get("runtime-option-raw", false);
        for (const auto& sw : thing.second.get_child("switches")) {
            Switch temp_switch;
            temp_switch.is_default = sw.second.get("default", false);
            temp_switch.name = sw.second.get("name", "");
            temp_switch.display_name = sw.second.get("display-name", "");
            temp_switch.display_flags = sw.second.get("display-flags", "");
            temp.switches.push_back(temp_switch);
        }
        for (const auto& t : thing.second.get_child("templates")) {
            temp.templates.push_back(t.second.get_value<std::string>());
        }
        temp.provider = thing.second.get("provider", 0);

        result.push_back(temp);
    }
    return result;
}

}  // namespace wandbox
