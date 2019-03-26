#include <wandbox/detail/get_connection.hpp>

#include <boost/asio.hpp>

#include <http/make_tls_connection.hpp>

namespace wandbox {
namespace detail {

const std::string host_k = "wandbox.org";

http::TLS_socket& get_connection() {
    static boost::asio::io_service io_s;  // performs disconnects on destruction
    static auto socket_ptr = http::make_tls_connection(host_k, io_s);
    return *socket_ptr;
}

}  // namespace detail
}  // namespace wandbox
