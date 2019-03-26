#ifndef WANDBOX_DETAIL_TO_RESULT_HPP
#define WANDBOX_DETAIL_TO_RESULT_HPP
#include <boost/property_tree/ptree.hpp>

namespace http {
struct HTTP_response;
}
namespace wandbox {
struct Result;
namespace detail {

Result to_result(const boost::property_tree::ptree& response);

}
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_RESULT_HPP
