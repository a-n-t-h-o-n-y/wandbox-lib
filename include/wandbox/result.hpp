#ifndef WANDBOX_RESULT_HPP
#define WANDBOX_RESULT_HPP
#include <string>

namespace wandbox {

struct Result {
    /// Exit code
    int status;

    /// Signal Message
    std::string signal;

    /// Compiler Standard Output
    std::string compiler_stdout;

    /// Compiler Error Output
    std::string compiler_stderr;

    /// Merged Messages of compiler_stdout and compiler_stderr
    std::string compiler_message;

    /// stdout at Runtime
    std::string program_stdout;

    /// stderr at Runtime
    std::string program_stderr;

    /// Merged Messages of program_stdout and program_stderr
    std::string program_message;

    /// Link to Solution if Compiler::save is true. Pass to GET /permlink/:link.
    std::string permlink;

    /// Browser Link to Solution if Compiler::save is true.
    std::string url;
};

}  // namespace wandbox
#endif  // WANDBOX_RESULT_HPP
