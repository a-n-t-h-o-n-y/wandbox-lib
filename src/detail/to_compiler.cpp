#include <wandbox/detail/to_compiler.hpp>

#include <string>

#include <boost/property_tree/ptree.hpp>

#include <wandbox/compiler.hpp>

namespace wandbox {
namespace detail {

Compiler to_compiler(const boost::property_tree::ptree& tree) {
    Compiler info;
    info.name = tree.get("name", "");
    info.display_name = tree.get("display-name", "");
    info.version = tree.get("version", "");
    info.language = tree.get("language", "");
    info.display_compile_command = tree.get("display-compile-command", "");
    info.compiler_option_raw = tree.get("compiler-option-raw", false);
    info.runtime_option_raw = tree.get("runtime-option-raw", false);
    for (const auto& sw : tree.get_child("switches")) {
        Switch option;
        option.is_default = sw.second.get("default", false);
        option.name = sw.second.get("name", "");
        option.display_name = sw.second.get("display-name", "");
        option.display_flags = sw.second.get("display-flags", "");
        info.switches.push_back(option);
    }
    for (const auto& t : tree.get_child("templates")) {
        info.templates.push_back(t.second.get_value<std::string>());
    }
    info.provider = tree.get("provider", 0);
    return info;
}

}  // namespace detail
}  // namespace wandbox
