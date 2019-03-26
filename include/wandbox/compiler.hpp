#ifndef WANDBOX_COMPILER_HPP
#define WANDBOX_COMPILER_HPP
#include <string>

namespace wandbox {

/// Data about the compiler and options passed to it for compilation.
struct Compiler {
    /// Compiler Name - Required
    std::string name;

    /// Standard Input
    std::string stdin;

    /// Used options for a compiler joined by comma.
    std::string options;

    /// Compile-time any additional options joined by line-breaks.
    std::string raw_compiler_options;

    /// Run-time any additional options joined by line-breaks.
    std::string raw_runtime_options;

    /// Generate permanent link if true.
    bool save{false};
};

}  // namespace wandbox
#endif  // WANDBOX_COMPILER_HPP
