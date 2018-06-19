#ifndef SUMBOL_HPP
#define SUMBOL_HPP

#include "smath.hpp"

class symbol{
public:

	/*
	 * check on controll symbol
	*/
	static bool is_ctrl(char c){
		if( SMATH::iRange( int(c), 31) )
			return true;
		return false;
	}

	/*
	 * min code in ascii table
	 */
	static int min(){
		return 1;
	}

	/*
	 * max code in ascii table
	 */
	static int max(){
		return 126;
	}

	/*
	 * get count controll symbols
	 */
	static int count_controlls(){
		return 31;
	}

};

#endif