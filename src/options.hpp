#ifndef OPTIONS_HPP
#define OPTIONS_HPP


#include <getopt.h>
#include "app.hpp"
#include "solution.hpp"
#include "crypto.hpp"

using namespace std;

class options{
public:

	/*
	 * function - parse user argument and build solution
	 * argc, argv arguments function main 
	 */
	static Solution parse(int argc, char *argv[]){

		Solution sol;

		int opt;
		struct option long_opt[] = {
			{"in", 		1, 0, 'i'},
			{"out", 	1, 0, 'o'},
			{"method", 	1, 0, 'm'},
			{"key", 	1, 0, 'k'},
			{"string", 	1, 0, 's'},
			{"genkey",	0, 0, 'g'},
			{"hide",  	0, 0, 'H'},
			{"encrypt", 0, 0, 'E'},
			{"decrypt", 0, 0, 'D'},
			{"debug", 	0, 0, 'd'},
			{"version", 0, 0, 'v'},
			{"help", 	0, 0, 'h'},
			{0, 		0, 0,  0 }
		};
		int opt_index;

		if( argc <= 1 ){
			app.warning("is few arguments");
			app.help();
		}

		while( true ){
			if( ( opt = getopt_long(argc, argv, "i:o:m:k:s:gHEDdvh", long_opt, &opt_index) ) == -1 )
				break;

			switch( opt ){
				case 'i':
					sol.setIn( optarg );
					break;
				case 'o':
					sol.setOut( optarg );
					break;
				case 'm':
					sol.setMethod( optarg );
					break;
				case 'k':
					sol.setKey( optarg );
					break;
				case 's':
					sol.setString( optarg );
					break;
				case 'g':
					sol.genkey = true;
					break;
				case 'H':
					sol.hide = true;
					break;
				case 'E':
					sol.setDirection( DIRECTION_ENCRYPT );
					break;
				case 'D':
					sol.setDirection( DIRECTION_DECRYPT );
					break;
				case 'd':
					app.isdbg = sol.debug = true;
					break;
				case 'v':
					app.version();
					break;
				case 'h':
					app.help();
					exit(0);
					break;
			}
		}

		return sol;
	}

	/*
	 * action options by solution
	 */
	static void action(Solution &sol){

		if( sol.getString().empty() ){

			if( !sol.getIn().empty() ){
				sol.setString( File::getContent( sol.getIn() ) );
				app.debug("in(" + sol.getIn() + ")");
			}
			else{
				app.error("you is not specify input text");
			}
		
		}

		app.debug("string(" + sol.getString() + ")");


		// check out file
		if( sol.getOut().empty() == false ){
			app.debug("out(" + sol.getOut() + ")");
		}

		// method
		if( sol.getMethod().empty() )
			app.error("you did not specify the method");

		app.debug("method(" + sol.getMethod() + ")");

		// direction (encrypt/decrypt)
		if( sol.getStringDirection().empty() )
			app.error("unknow direction, select encrypt or decrypt");

		app.debug("direction(" + sol.getStringDirection() + ")");

		// genkey
		if( sol.genkey ){

			// gen and set key
			sol.setKey( security.genkey( sol.getMethod() ) );

			// output key
			if( !sol.hide ){
				app.info("key was generated: '" + sol.getKey() + "'");
			}

		}

		// create key file, if direction encrypt
		if( sol.getDirection() == DIRECTION_ENCRYPT ){
			File::setContent(sol.getKey(), sol.getOut() + ".key");
		}

		// check key
		if( sol.getKey().empty() )
			app.error("key is not specify");
		
		app.debug("key(" + sol.getKey() + ")");

	}

};

#endif