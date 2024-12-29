#include "tcp_server.hpp"

#include <functional>

using namespace asio::ip;

tcp_server::tcp_server(asio::io_context& io_context)
  : m_io_context(io_context),
    m_acceptor(io_context, tcp::endpoint(tcp::v4(), 13)) {
  start_accept();
}

void tcp_server::start_accept() {
  tcp_connection::pointer new_connection = tcp_connection::create(m_io_context);
  m_acceptor.async_accept(new_connection->socket(), std::bind(&tcp_server::handle_accept, this, new_connection, asio::placeholders::error));

}

void tcp_server::handle_accept(tcp_connection::pointer new_connection, const std::error_code& error) {
  if (!error) {
    new_connection->start();
  }
  start_accept();
}