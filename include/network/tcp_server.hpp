#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <system_error>

#include "tcp_connection.hpp"

class tcp_server {
 private:
  asio::io_context& m_io_context;
  asio::ip::tcp::acceptor m_acceptor;

 public:
  tcp_server(asio::io_context& context);

  void start_accept();
  void handle_accept(tcp_connection::pointer new_connection, const std::error_code& error);
};

#endif  // TCP_SERVER_HPP