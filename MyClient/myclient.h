#ifndef MYCLIENT_H_
#define MYCLIENT_H_

#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>

//------------------------------------------------------------------------

class TMyClient
{
public:	
	TMyClient() = default;
	virtual ~TMyClient();

	void Connect(const char* ip);
	void SendMessage(const char* msg);

private:
	boost::asio::io_context io {};
	boost::asio::ip::tcp::socket socket {io};
	boost::asio::ip::tcp::resolver resolver {io};
};

//------------------------------------------------------------------------

#endif