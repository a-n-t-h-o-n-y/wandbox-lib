#ifndef WANDBOX_DETAIL_SEND_HPP
#define WANDBOX_DETAIL_SEND_HPP

#include <boost/property_tree/ptree.hpp>

namespace http {
struct HTTP_request;
}
namespace wandbox {
namespace detail {

boost::property_tree::ptree send(const http::HTTP_request& request);

}
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_SEND_HPP
