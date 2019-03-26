#ifndef WANDBOX_COMPILE_HPP
#define WANDBOX_COMPILE_HPP
#include <string>

#include <wandbox/result.hpp>

namespace wandbox {
struct Compiler;

Result compile(const Compiler& context, const std::string& code);

}  // namespace wandbox
#endif  // WANDBOX_COMPILE_HPP
