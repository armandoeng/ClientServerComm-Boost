#ifndef MYSERVER_H_
#define MYSERVER_H_

#include <boost/asio.hpp>

#include "myconnection.h"

//---------------------------------------------------------------------------------------

class TMyServer
{
public:		
	TMyServer() = default;
	virtual ~TMyServer() = default;

	void Listen();
	
private:	
	void HandleAccept(
		TMyConnection::pointer new_connection,
		const boost::system::error_code& error
	);
	
	void SaveMessage(const char* msg);

	boost::asio::io_service io {};
};

//---------------------------------------------------------------------------------------

#endif