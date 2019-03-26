#ifndef WANDBOX_DETAIL_TO_RESULT_HPP
#define WANDBOX_DETAIL_TO_RESULT_HPP
#include <boost/property_tree/ptree.hpp>

namespace http {
struct HTTP_response;
}
namespace wandbox {
struct Result;
namespace detail {

/// Parses a boost::ptree for data about a compilation result.
Result to_result(const boost::property_tree::ptree& tree);

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_RESULT_HPP
