#ifndef BUILD_HPP
#define BUILD_HPP

#include "const.h"
#include "solution.hpp"
#include "options.hpp"
#include "file.hpp"
#include "crypto.hpp"


using namespace std;


// output information
void outi(Solution, string, string);

// output content in out file, if he was specified
void out_content(Solution &, const string);


/*
 * init - main function, 
 * parse argument command line , 
 * that get source content ,
 * that encrypt text and output result in stdout or file  
 */
void init(int argc, char *argv[]){

	// init vars
	string scrypto, ssource;

	// parse user arguments
	Solution solution = options::parse( argc, argv );
	options::action( solution );

	// get content from in-file
	ssource = solution.getString();

	// encrypt content
	scrypto = security.crypto(solution, ssource);

	// write chipher in out-file
	out_content(solution, scrypto);

	// output final inforamtion
	outi( solution, ssource, scrypto);

}

/*
 * output content in out file, contain in solution,
 * insert user options 
 * @param (solution) - solution from parsing options
 * @param (result) 	 - result content output in file
 */
void out_content( Solution &solution, const string content ){
	if( !solution.getOut().empty() ){
		File::setContent( content, solution.getOut() );
	}
}


/*
 * output information
 * solution class Solution
 */
void outi( Solution solution, string source, string result ){
	
	string process;

	if( !solution.hide ){ 

		// output source text
		cout << endl << "- Source -" << endl;
		cout << source << endl << endl;

		// output result
		if( solution.getDirection() == DIRECTION_DECRYPT )
			process = "- Decryption -";
		else
			process = "- Cryption -";
		
		cout << process << endl;
		cout << result << endl << endl;
		
	}
}

#endif