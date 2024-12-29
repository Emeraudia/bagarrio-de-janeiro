#ifndef TCP_CONNECTION_HPP
#define TCP_CONNECTION_HPP

#include <asio.hpp>

class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
 private:
  asio::ip::tcp::socket m_socket;
  std::string m_message;

 public:
  typedef std::shared_ptr<tcp_connection> pointer;

  static pointer create(asio::io_context& io_context);

  void start();
  void handle_write(const std::error_code& error, size_t bytes);
  asio::ip::tcp::socket& socket();

 private:
  tcp_connection(asio::io_context& io_context);
};

#endif  // TCP_CONNECTION_HPP