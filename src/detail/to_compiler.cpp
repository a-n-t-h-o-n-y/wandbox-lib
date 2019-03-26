#include <wandbox/detail/to_compiler.hpp>

#include <boost/property_tree/ptree.hpp>

#include <wandbox/compiler.hpp>

namespace wandbox {
namespace detail {

Compiler to_compiler(const boost::property_tree::ptree& tree) {
    Compiler result;
    result.name = tree.get("compiler", "");
    result.stdin = tree.get("stdin", "");
    result.options = tree.get("options", "");
    result.raw_compiler_options = tree.get("compiler-option-raw", "");
    result.raw_runtime_options = tree.get("runtime-option-raw", "");
    result.save = tree.get("save", false);
    return result;
}

}  // namespace detail
}  // namespace wandbox
