#ifndef CONSOLE_HPP
#define CONSOLE_HPP

using namespace std;

/*
	DEFAULT 	= "\x1b[0m"
	RED 		= "\x1b[031;1m"
	GREEN 		= "\x1b[032;1m"
	BLUE 		= "\x1b[034;1m"
	PURPLE 		= "\x1b[035;1m"
	
	WARNING 	= PURPLE
	ERROR 		= RED
	SUCCESS 	= GREEN
	INFO		= BLUE
*/

class CONSOLE{
public:
	
	/*
     * function witch return color code for linux
	*/

	static string ORIGIN(){
		return "\x1b[0m";
	}
	static string RED(){
		return "\x1b[031m";
	}
	static string GREEN(){
		return "\x1b[032m";
	}
	static string BLUE(){
		return "\x1b[034m";
	}
	static string PURPLE(){
		return "\x1b[035m";
	}
	static string YELLOW(){
		return "\x1b[033m";
	}

	static string INFO(){
		return BLUE();
	}
	static string WARNING(){
		return YELLOW();
	}
	static string ERROR(){
		return RED();
	}
	static string SUCCESS(){
		return GREEN();
	}

};

#endif