#ifndef WANDBOX_DETAIL_GET_CONNECTION_HPP
#define WANDBOX_DETAIL_GET_CONNECTION_HPP
#include <http/make_tls_connection.hpp>

namespace wandbox {
namespace detail {

extern const std::string host_k;

/// Assume the application will only every use a single connection.
/// Returns the global socket with the connection to wandbox.org
http::TLS_socket& get_connection();

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_GET_CONNECTION_HPP
