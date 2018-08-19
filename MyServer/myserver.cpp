#include "myserver.h"

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include <iostream>

#include "myinput.h"

//------------------------------------------------------------------------

void TMyServer::HandleAccept(
	TMyConnection::pointer new_connection,
	const boost::system::error_code& error
)
{
	if (!error) {
		new_connection->Start();
	}
	else{		
		std::cout << "Error: " << error.message().c_str() << std::endl;
	}
}
 
//------------------------------------------------------------------------

void TMyServer::Listen()
{		
	try{
		using namespace boost::asio::ip;
		tcp::endpoint endpoint(tcp::v4(), TMyInput::GetPort());
		tcp::acceptor acceptor(io, endpoint);
		
		const unsigned int maxFileBuffer = TMyInput::GetFileSize();
		std::string msg;
		
		char tempMsg[maxFileBuffer];
		boost::asio::mutable_buffer buffer(tempMsg, maxFileBuffer);
		while(msg.size() < maxFileBuffer){
			io.restart();
			
			TMyConnection::pointer new_connection = TMyConnection::Create(acceptor.get_io_service(), buffer);
			acceptor.async_accept(
				new_connection->Socket(),
				boost::bind(&TMyServer::HandleAccept, this, new_connection, boost::asio::placeholders::error)
			);
			io.run();
			
			msg.append(tempMsg);
		}
		
		msg.resize(maxFileBuffer);
		SaveMessage(msg.c_str());
	}
	catch (std::exception& e){		
		std::cerr << e.what() << std::endl;
	}
}
	
//------------------------------------------------------------------------

void TMyServer::SaveMessage(const char* msg)
{		
	boost::filesystem::path p{"message.txt"};
	boost::filesystem::ofstream ofs{p};
	ofs << msg;
}

//------------------------------------------------------------------------
