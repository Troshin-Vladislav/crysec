#ifndef CRYPTO_HPP
#define CRYPTO_HPP


#include "const.h"
#include "app.hpp"
#include "smath.hpp"
#include "solution.hpp"
#include "symbol.hpp"

class Security{
public:

	/*
	 * encryption info link to built solution
	 * @param (sol) - built solution
	 * @param (content) - encrypt content
	 */
	string crypto(Solution sol, string content){

		string result;

		switch( sol.getDirection() ){
			case DIRECTION_ENCRYPT:
				result = encrypt( sol.getMethod(), sol.getKey(), content );
				break;
			case DIRECTION_DECRYPT:
				result = decrypt( sol.getMethod(), sol.getKey(), content );
				break;
		}

		return result;
	}

	/*
	 * encrypt text for select method
	 * @param (method) 	- set method
	 * @param (key) 	- key
	 * @param (source) 	- source text
	 */
	string encrypt(string method, string key, string source){

		string encode;

		if( method == "caesar" )
			encode = caesar(source, key);
		else if( method == "xor" )
			encode = cxor(source, key);
		else
			app.error("unknow algorithm encryption");

		return encode;
	}

	/*
	 * decrypt text for select method
	 * @param (method) 	- set method
	 * @param (key) 	- key
	 * @param (source) 	- source text
	 */
	string decrypt(string method, string key, string source){

		string decode;

		if( method == "caesar" )
			decode = caesar(source, key, false);
		else if( method == "xor" )
			decode = cxor(source, key); 
		else
			app.error("selected your decryption algorithm is not");

		return decode;
	}

	/*
	 * encrypt and decrypt content by operation xor
	*/
	string cxor(string source, string key){

		string result;
		char letter;
		unsigned int pos_key = 0;

		for( char ch : source ){

			if( pos_key >= key.length() ){
				pos_key = 0;
			}

			letter = ch ^ key[pos_key];
			result += letter;

			pos_key++;
		}

		return result;
	}

	/*
	 * encode string by method Ceasar
	 * @param (source) - source string
	 * @param (offset) - set offset  
	 */
	string caesar(string source, int offset, bool encrypt = true){
		
		string result;
		int letter;


		if( !SMATH::iRange(offset, 95, 1) ){
			app.error("offset is not could bigger 95 and less 1");
		}

		for( char ch : source ){

			// check special symbol
			if( symbol::is_ctrl( ch ) ){
				result += ch;
				continue;
			}

			// select encrypt or decrypt
			if( encrypt ) letter = ch + offset;
			else          letter = ch - offset;


			if( letter >= 127 ){
				letter = letter - 95;
			}
			else if( letter <= 31 ){
				letter = letter + 95;
			}

			result += letter;
		}

		return result;
	}

	/*
	 * genkey for method caesar
	 */
	string genkey_caesar(){
		int r = SMATH::random(symbol::min(), symbol::count_controlls() );
		return to_string( r );
	}

	/*
	 *  genkey for method xor
	*/
	string genkey_xor(){
		char r = SMATH::random(symbol::min(), symbol::max());
		string genstr = { r };
		return genstr;
	}

	/*
	 * multi generation key by specify method 
	 * @param (method) - method encryption
	 */
	string genkey(string method){

		string gkey;

		if( method == "caesar" )
			gkey = genkey_caesar();
		else if( method == "xor" )
			gkey = genkey_xor();
		else
			app.error("unknow method for a generation key");

		return gkey;
	}

	/*
	 * @override function
	 * convert string offset to int and return to original function
	 */
	string caesar(string source, string offset, bool encrypt = true){

		int key = std::stoi( offset );
		return caesar(source, key, encrypt);

	}

};

Security security = Security();

#endif