#ifndef WANDBOX_DETAIL_TO_STRING_HPP
#define WANDBOX_DETAIL_TO_STRING_HPP
#include <string>

namespace wandbox {
struct Compiler;
struct Compiler_info;
struct Result;
struct Switch;

namespace detail {

std::string to_string(const Compiler& context, const std::string& code);

std::string to_string(const Result& result);

std::string to_string(const Switch& s);

std::string to_string(const Compiler_info& info);

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_STRING_HPP
