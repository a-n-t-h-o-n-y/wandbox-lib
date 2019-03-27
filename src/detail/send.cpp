#include <wandbox/detail/send.hpp>

#include <memory>
#include <stdexcept>

#include <boost/property_tree/ptree.hpp>

#include <http/http_request.hpp>
#include <http/http_response.hpp>
#include <http/make_tls_connection.hpp>
#include <http/parse/json_ptree.hpp>
#include <http/read.hpp>
#include <http/send.hpp>

#include <wandbox/detail/get_connection.hpp>

namespace {
/// Get connection to wandbox.org
auto connect() {
    static boost::asio::io_service io_s;  // performs disconnects on destruction
    return http::make_tls_connection(wandbox::detail::host_k, io_s);
}

/// Returns the global socket with the connection to wandbox.org
std::unique_ptr<http::TLS_socket>& get_connection() {
    static auto socket_ptr = connect();
    return socket_ptr;
}

}  // namespace

namespace wandbox {
namespace detail {

boost::property_tree::ptree send(const http::HTTP_request& request) {
    http::HTTP_response response;
    while (true) {
        try {
            http::send(request, *get_connection());
            response = http::read(*get_connection());
            break;
        } catch (const std::runtime_error&) {
            get_connection() = connect();
        }
    }
    return http::parse::json_ptree(response.message_body);
}

}  // namespace detail
}  // namespace wandbox
