#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "const.h"
#include "file.hpp"

using namespace std;

class Solution{
private:
	string in;
	string out;
	string method;
	string key;
	string str;

	int direction = 0;

public:

	// vars
	bool debug 	= false;
	bool hide 	= false;
	bool genkey = false;

	// setters
	void setIn(string in){
		this->in = in;
	}
	
	void setOut(string out){
		this->out = out;
	}

	void setMethod(string method){
		this->method = method;
	}

	void setDirection(int dir){
		if( (dir == DIRECTION_ENCRYPT) || 
			(dir == DIRECTION_DECRYPT) )
		{
			this->direction = dir;
		}
	}

	void setKey(string str){

		string res;

		if( File::is_sfile( str ) )
			res = File::getContent( str );
		else
			res = str;

		this->key = res;

	}

	void setString(string str){
		this->str = str;
	}


	// getters
	string getIn(){
		return this->in;
	}

	string getOut(){
		return this->out;
	}

	string getMethod(){
		return this->method;
	}

	int getDirection(){
		return this->direction;
	}

	string getKey(){
		return this->key;
	}

	string getString(){
		return this->str;
	}

	string getStringDirection(){
		
		string res = "";

		switch( this->direction ){
			case DIRECTION_ENCRYPT:
				res = "encrypt";
				break;
			case DIRECTION_DECRYPT:
				res = "decrypt";
				break;
		}

		return res;
	}

};

#endif