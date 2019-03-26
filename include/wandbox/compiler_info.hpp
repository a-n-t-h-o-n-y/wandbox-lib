#ifndef WANDBOX_COMPILER_INFO_HPP
#define WANDBOX_COMPILER_INFO_HPP
#include <string>
#include <vector>

#include <wandbox/switch.hpp>

namespace wandbox {

struct Compiler_info {
    std::string name;
    std::string display_name;
    std::string version;
    std::string language;
    std::string display_compile_command;
    bool compiler_option_raw;
    bool runtime_option_raw;
    std::vector<Switch> switches;
    std::vector<std::string> templates;
    int provider;
};

}  // namespace wandbox
#endif  // WANDBOX_COMPILER_INFO_HPP
