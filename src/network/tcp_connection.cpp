#include "tcp_connection.hpp"

#include <asio/io_context.hpp>
#include <asio/placeholders.hpp>
#include <asio/write.hpp>
#include <cstddef>
#include <functional>
#include <system_error>

std::string make_daytime_string() {
  std::time_t now = time(0);
  return std::ctime(&now);
}

tcp_connection::tcp_connection(asio::io_context& io_context)
    : m_socket(io_context) {
}

tcp_connection::pointer tcp_connection::create(asio::io_context& io_context) {
  return pointer(new tcp_connection(io_context));
}

void tcp_connection::start() {
  m_message = make_daytime_string();
  asio::async_write(m_socket, asio::buffer(m_message), std::bind(&tcp_connection::handle_write, shared_from_this(), asio::placeholders::error, asio::placeholders::bytes_transferred));
}

void tcp_connection::handle_write(const std::error_code& error, size_t bytes) {
}

asio::ip::tcp::socket& tcp_connection::socket() {
  return m_socket;
}