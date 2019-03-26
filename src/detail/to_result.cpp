#include <wandbox/detail/to_result.hpp>

#include <boost/property_tree/ptree.hpp>

#include <wandbox/result.hpp>

namespace wandbox {
namespace detail {

Result to_result(const boost::property_tree::ptree& tree) {
    Result result;
    result.status = tree.get("status", -128);
    result.signal = tree.get("signal", "");
    result.compiler_stdout = tree.get("compiler_output", "");
    result.compiler_stderr = tree.get("compiler_error", "");
    result.compiler_message = tree.get("compiler_message", "");
    result.program_stdout = tree.get("program_output", "");
    result.program_stderr = tree.get("program_error", "");
    result.program_message = tree.get("program_message", "");
    result.permlink = tree.get("permlink", "");
    result.url = tree.get("url", "");
    return result;
}

}  // namespace detail
}  // namespace wandbox
