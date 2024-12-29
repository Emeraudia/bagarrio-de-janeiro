#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <asio.hpp>
#include <string>

class tcp_client {
 private:
  asio::io_context m_io_context;
  asio::ip::tcp::socket m_socket;

 public:
  tcp_client(const std::string& host, const std::string& port);
  ~tcp_client();

  void send_message(const std::string& message);
  std::string receive_message();
  void close();
};

#endif  // TCP_CLIENT_HPP