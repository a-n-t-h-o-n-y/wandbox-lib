#ifndef WANDBOX_DETAIL_TO_SESSION_HPP
#define WANDBOX_DETAIL_TO_SESSION_HPP
#include <boost/property_tree/ptree.hpp>

#include <wandbox/session.hpp>

namespace wandbox {
namespace detail {

/// parses a boost::ptree for data about a Session.
Session to_session(const boost::property_tree::ptree& tree);

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_SESSION_HPP
