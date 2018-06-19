#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include "app.hpp"

using namespace std;

class File{
public:

	/*
	 * get content from file 
	 */
	static string getContent(string filename){

		ifstream fin( filename );
		string line, content;
		char ch;

		if( !fin.is_open() ){
			app.error("file(" + filename + ") is could not open");
		}

		while( fin.get(ch) ){
			content += ch;
		}

		return content;
	}

	/*
	 * write content to file
	 */
	static void setContent(string content, string filename){

		ofstream fout( filename );

		if( !fout.is_open() ){
			app.error("file(" + filename + ") is could not open");
		}

		fout << content;
		fout.close();
	}

	/*
	 * is file is simple file, no '.', '..', '~', ... 
	 * @param (fname) - name checked file
	 */
	static bool is_sfile(string fname){

		bool result = false;

		if( File::bad_fname( fname ) )
			return result;


		ifstream f( fname );

		if( f.is_open() ){
			result = true;
			f.close();
		}

		return result;
	}

	/*
	 * check name file 
	 */
	static bool bad_fname(string name){

		if( name == "." )
			return true;
		else if( name == ".." )
			return true;
		else if( name == "~" )
			return true;

		return false;
	}

};

#endif