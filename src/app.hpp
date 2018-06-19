#ifndef APP_HPP
#define APP_HPP

#include "const.h"
#include "console.hpp"

using namespace std;

class App{
private:
	string name = "crysec";
	string description  = "security info";
	
public:

	bool isdbg = false;

	// getters

	// get name this application
	string getName(){
		return this->name;
	}

	// get description this application
	string getDescription(){
		return this->description;
	}

	/*
	 * show help page
	 */
	void help(){
		usage();
		cout << "  -i, --in:*\n" 		<< "  Specified in file" 				<< endl << endl;
		cout << "  -o, --out:\n" 		<< "  Specified out file" 				<< endl << endl;
		cout << "  -m, --method:*\n" 	<< "  Set algorithm chipther" 			<< endl;
		cout << "  'caesar' - Algorithm Caesar" 								<< endl;
		cout << "  'xor'    - Algorithm with operation xor" 					<< endl << endl;
		cout << "  -g, --genkey:\n" 	<< "  Generation key" 					<< endl << endl;
		cout << "  -k, --key:*\n" 		<< "  Set ket" 							<< endl << endl;
		cout << "  -s, --string:\n" 	<< "  Specify string as argument" 		<< endl << endl;
		cout << "  -H, --hide:\n" 		<< "  Turn off output console" 			<< endl << endl;
		cout << "  -E, --encrypt:*\n" 	<< "  Encrypt mode" 					<< endl << endl;
		cout << "  -D, --decrypt:*\n" 	<< "  Decrypt mode" 					<< endl << endl;
		cout << "  -d, --debug:\n" 		<< "  Turn on debug mode"			 	<< endl << endl;
		cout << "  -v, --version:\n" 	<< "  Show version program and exit" 	<< endl << endl;
		cout << "  -h, --help:\n" 		<< "  Show help page and exit" 			<< endl << endl;
		exit(0);
	}

	/*
	 * output usage program
	 */
	void usage(){
		cout << "usage: " << this->getName() << " (--in <file>|--string <string>) ";
		cout << "--method <method> ";
		cout << "(--key <key>|--genkey) ";
		cout << "(--encrypt|--decrypt) [options...] " << endl << endl;
	}

	/*
	 *  show version program
	 */
	void version(){
		cout << "crysec [" << CONSOLE::GREEN() << VERSION_APP << CONSOLE::ORIGIN() << "]" << endl;
		
		out_new_version("add function auto generation key");
		out_new_version("add direct reference to string");
		out_new_version("fixed more bags...");
		
		exit(0);
	}

	/*
	 * output one line witch add in new version
	 * for optimization
	 * @param (message) - description for outputing line
	 */
	void out_new_version(string message){
		cout << "  [" << CONSOLE::GREEN() << "+" << CONSOLE::ORIGIN() << "]: ";
		cout << message << endl;
	}

	/*
	 * all notifi functions is print message on error output (cerr - 2)
	*/

	// show debug message
	void debug(string message){
		if( this->isdbg ){
			cerr << "[" << CONSOLE::GREEN() << "debug" << CONSOLE::ORIGIN() << "]: " << message << endl;
		}
	}

	// show warning message
	void warning(string message){
		cerr << "[" + CONSOLE::WARNING() + "warning" + CONSOLE::ORIGIN() +"]: " << message << endl;
	}

	// @overload
	void error(string message, int code = 1){
		cerr << "[" + CONSOLE::ERROR() + "error" + CONSOLE::ORIGIN() +"]: " << message << endl;
		exit( code );
	}

	// show info message
	void info(string message){
		cerr << "[" + CONSOLE::INFO() + "info" + CONSOLE::ORIGIN() +"]: " << message << endl;
	}

	// show success message
	void success(string message){
		cerr << "[" + CONSOLE::SUCCESS() + "access" + CONSOLE::ORIGIN() +"]: " << message << endl;
	}

};

App app = App();

#endif