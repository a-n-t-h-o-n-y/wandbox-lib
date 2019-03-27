#ifndef WANDBOX_COMPILE_HPP
#define WANDBOX_COMPILE_HPP
#include <string>

#include <wandbox/result.hpp>

namespace wandbox {
struct Session;

/// Send \p code off to be compiled by Wandbox, with \p context settings.
/** Throws std::runtime_error if there are issues with connection or request. */
Result compile(const Session& context, const std::string& code);

}  // namespace wandbox
#endif  // WANDBOX_COMPILE_HPP
