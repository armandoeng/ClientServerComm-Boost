# ClientServerComm-Boost
This is a simple example of client-server communication using boost.  This was my first time programming in Linux (Cygwin) using makefile, so I tried to do everything very simple.

- MyCLient - client class responsible for sending messages.
- MyServer - server class responsible for receiving messages, and create a file with the these messages, as soon as the number of selected bytes is reached.
- MyInput - A class that reads a Json file which contains input for the MyClient and MyServer classes. It has the port number to connect and the number of bytes that the final message file must have. I compiled this class to be both used as a dynamic and static library.
