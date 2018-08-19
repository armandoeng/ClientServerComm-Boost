#include "myconnection.h"

#include <boost/bind.hpp>

#include <iostream>

//------------------------------------------------------------------------

TMyConnection::TMyConnection(
	boost::asio::io_service& io_service,
	boost::asio::mutable_buffer& _buffer
)
: buffer(_buffer),
  socket(io_service)
{
}
  
//------------------------------------------------------------------------

TMyConnection::~TMyConnection()
{
	Disconnect();
}

//------------------------------------------------------------------------

TMyConnection::pointer TMyConnection::Create(
	boost::asio::io_service& io_service,
	boost::asio::mutable_buffer& _buffer
)
{
	return pointer(new TMyConnection(io_service, _buffer));
}

//------------------------------------------------------------------------

void TMyConnection::Start()
{
	boost::asio::async_read(
		socket, buffer,
		boost::bind(
			&TMyConnection::HandleRead, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);
}

//------------------------------------------------------------------------

void TMyConnection::HandleRead(
	const boost::system::error_code& error,
	size_t /*bytes_transferred*/
)
{
	if(!error){
		std::cout << "Message: " << static_cast<unsigned char*>(buffer.data()) << std::endl;
	}
	else{
		std::cout << "Error: " << error.message().c_str() << std::endl;
	}
}

//------------------------------------------------------------------------

void TMyConnection::Disconnect()
{
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	socket.close();
}

//------------------------------------------------------------------------
