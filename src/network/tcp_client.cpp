#include "tcp_client.hpp"


tcp_client::tcp_client(const std::string& host, const std::string& port)
    : m_io_context(), m_socket(m_io_context) {
}

tcp_client::~tcp_client() {
}

void tcp_client::send_message(const std::string& message) {
    asio::write(m_socket, asio::buffer(message));
}

std::string tcp_client::receive_message() {
    char buffer[1024];
    size_t length = m_socket.read_some(asio::buffer(buffer));
    return std::string(buffer, length);
}

void tcp_client::close() {
    m_socket.close();
}