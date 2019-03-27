#ifndef WANDBOX_GET_TEMPLATE_HPP
#define WANDBOX_GET_TEMPLATE_HPP
#include <string>

namespace wandbox {

/// Get the template code associated with \p name.
/** Throws std::runtime_error if there are issues with connection or request. */
std::string get_template(const std::string& name);

}  // namespace wandbox
#endif  // WANDBOX_GET_TEMPLATE_HPP
