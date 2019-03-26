#include <wandbox/detail/to_result.hpp>

#include <boost/property_tree/ptree.hpp>

#include <http/http_response.hpp>
#include <http/parse/json_ptree.hpp>

#include <wandbox/result.hpp>

namespace wandbox {
namespace detail {

Result to_result(const boost::property_tree::ptree& response) {
    Result result;
    result.status = response.get("status", -128);
    result.signal = response.get("signal", "");
    result.compiler_stdout = response.get("compiler_output", "");
    result.compiler_stderr = response.get("compiler_error", "");
    result.compiler_message = response.get("compiler_message", "");
    result.program_stdout = response.get("program_output", "");
    result.program_stderr = response.get("program_error", "");
    result.program_message = response.get("program_message", "");
    result.permlink = response.get("permlink", "");
    result.url = response.get("url", "");
    return result;
}

}  // namespace detail
}  // namespace wandbox
