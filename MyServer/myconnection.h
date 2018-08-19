#ifndef MYCONNECTION_H_
#define MYCONNECTION_H_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

//---------------------------------------------------------------------------------------

class TMyConnection : public boost::enable_shared_from_this<TMyConnection>
{
public:
	using pointer = boost::shared_ptr<TMyConnection>;

	TMyConnection() = delete;
	virtual ~TMyConnection();

	static pointer Create(
		boost::asio::io_service& io_service,
		boost::asio::mutable_buffer& _buffer
	);
	
	boost::asio::ip::tcp::socket& Socket()
	{
		return socket;
	}

	void Start();
	
	void Disconnect();

private:
	TMyConnection(
		boost::asio::io_service& io_service,
		boost::asio::mutable_buffer& _buffer
	);

	void HandleRead(
		const boost::system::error_code& error,
		size_t /*bytes_transferred*/
	);

	boost::asio::mutable_buffer& buffer;
	boost::asio::ip::tcp::socket socket;	
};

//---------------------------------------------------------------------------------------

#endif