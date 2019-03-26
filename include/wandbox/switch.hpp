#ifndef WANDBOX_SWITCH_HPP
#define WANDBOX_SWITCH_HPP
#include <string>

namespace wandbox {

/// Compiler switch provided by Wandbox.
struct Switch {
    bool is_default;
    std::string name;
    std::string display_name;
    std::string display_flags;
};

}  // namespace wandbox
#endif  // WANDBOX_SWITCH_HPP
