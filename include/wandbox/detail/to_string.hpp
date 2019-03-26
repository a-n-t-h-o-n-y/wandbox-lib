#ifndef WANDBOX_DETAIL_TO_STRING_HPP
#define WANDBOX_DETAIL_TO_STRING_HPP
#include <string>

namespace wandbox {
struct Session;
struct Compiler;
struct Result;
struct Switch;

namespace detail {

/// Return a string representation of the \p context and \p code.
std::string to_string(const Session& context, const std::string& code);

/// Return a string representation of the \p result.
std::string to_string(const Result& result);

/// Return a string representation of the \p option.
std::string to_string(const Switch& option);

/// Return a string representation of the \p info.
std::string to_string(const Compiler& info);

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_STRING_HPP
