#include <wandbox/detail/to_string.hpp>

#include <string>

#include <wandbox/compiler.hpp>
#include <wandbox/compiler_info.hpp>
#include <wandbox/result.hpp>
#include <wandbox/switch.hpp>

namespace {

std::string join(const std::string& key, const std::string& value) {
    if (value.empty()) {
        return "";
    }
    return "\"" + key + "\":\"" + value + "\",\n";
}

}  // namespace

namespace wandbox {
namespace detail {

std::string to_string(const Compiler& context, const std::string& code) {
    std::string result{"{\n"};
    result += join("code", code);
    result += join("compiler", context.name);
    result += join("stdin", context.stdin);
    result += join("options", context.options);
    result += join("compiler-option-raw", context.raw_compiler_options);
    result += join("runtime-option-raw", context.raw_runtime_options);
    result += join("save", context.save ? "true" : "");
    result += "}";
    return result;
}

std::string to_string(const Result& result) {
    std::string output;
    output += "status: " + std::to_string(result.status) + '\n';
    output += "signal: " + result.signal + '\n';
    output += "compiler_stdout: " + result.compiler_stdout + '\n';
    output += "compiler_stderr: " + result.compiler_stderr + '\n';
    output += "compiler_message: " + result.compiler_message + '\n';
    output += "program_stdout: " + result.program_stdout + '\n';
    output += "program_stderr: " + result.program_stderr + '\n';
    output += "program_message: " + result.program_message + '\n';
    output += "permlink: " + result.permlink + '\n';
    output += "url: " + result.url + '\n';
    return output;
}

std::string to_string(const Switch& s) {
    std::string output;
    output += "default: " + std::string(s.is_default ? "true" : "false") + '\n';
    output += "name: " + s.name + '\n';
    output += "display_name: " + s.display_name + '\n';
    output += "display_flats: " + s.display_flags + '\n';
    return output;
}

std::string to_string(const Compiler_info& info) {
    std::string output;
    output += "name: " + info.name + '\n';
    output += "display_name: " + info.display_name + '\n';
    output += "version: " + info.version + '\n';
    output += "language: " + info.language + '\n';
    output += "display_compile_command: " + info.display_compile_command + '\n';
    output += "compiler_option_raw: " +
              std::string(info.compiler_option_raw ? "true" : "false") + '\n';
    output += "runtime_option_raw: " +
              std::string(info.runtime_option_raw ? "true" : "false") + '\n';
    for (const auto& s : info.switches) {
        output += "switch:\n";
        output += to_string(s) + '\n';
    }
    output += "templates: ";
    std::string separator{""};
    for (const auto& t : info.templates) {
        output += separator + t;
        separator = ", ";
    }
    output += '\n';
    output += "provider: " + std::to_string(info.provider) + '\n';
    return output;
}

}  // namespace detail
}  // namespace wandbox
