#include "myclient.h"

#include <iostream>

int main(int argc, char* argv[])
{	
	if(argc < 2){
		return 1;
	}

	TMyClient client;
	client.Connect("127.0.0.1");

	const char* msg = argv[1];
	std::cout << "Mensagem Enviada: " << msg << std::endl;
	client.SendMessage(msg);
	return 0;
}