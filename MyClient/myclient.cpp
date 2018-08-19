#include "myclient.h"

#include <iostream>

#include "myinput.h"

//------------------------------------------------------------------------

TMyClient::~TMyClient()
{
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	socket.close();
}

//------------------------------------------------------------------------

void TMyClient::Connect(
	const char* ip
)
{
	char port[16];
	sprintf(port, "%i", TMyInput::GetPort());
	boost::asio::connect(socket, resolver.resolve({ip, port}));	
}

//------------------------------------------------------------------------
	
void TMyClient::SendMessage(
	const char* msg
)
{
	const unsigned int size = TMyInput::GetFileSize();
	boost::asio::write(socket, boost::asio::buffer(msg, size));
}

//------------------------------------------------------------------------
	