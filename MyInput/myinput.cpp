#include "myinput.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <string>

const char* TMyInput::fileName = "input.json";

//------------------------------------------------------------------------

int TMyInput::GetPort()
{
	boost::property_tree::ptree tree;
	boost::property_tree::read_json(fileName, tree);
	std::string port = tree.get<std::string> ("Port");

	if(!port.empty()){
		return std::stoi(port);
	}
		
	return 2000;
}

//------------------------------------------------------------------------

int TMyInput::GetFileSize()
{
	boost::property_tree::ptree tree;
	boost::property_tree::read_json(fileName, tree);
	std::string size = tree.get<std::string> ("Size");

	if(!size.empty()){
		return std::stoi(size);
	}
	
	return 1024;
}
	
//------------------------------------------------------------------------
