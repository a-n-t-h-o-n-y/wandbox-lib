#include <wandbox/get_list.hpp>

#include <algorithm>
#include <vector>

#include <boost/property_tree/ptree.hpp>

#include <http/generate/basic_get_request.hpp>
#include <http/http_request.hpp>

#include <wandbox/compiler.hpp>
#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/send.hpp>
#include <wandbox/detail/to_compiler.hpp>

namespace {
using namespace wandbox;

auto parse(const boost::property_tree::ptree& compiler_tree) {
    auto result = std::vector<Compiler>{};
    std::transform(std::begin(compiler_tree), std::end(compiler_tree),
                   std::back_inserter(result), [](const auto& child) {
                       return detail::to_compiler(child.second);
                   });
    return result;
}
}  // namespace

namespace wandbox {

std::vector<Compiler> get_list() {
    const auto request = http::generate::basic_GET_request(
        detail::host_k, "/api/list.json", false);
    const auto compilers_json = detail::send(request);
    return parse(compilers_json);
}
}  // namespace wandbox
