#ifndef SMATH_HPP
#define SMATH_HPP

#include <random>

class SMATH{
public:

	/*
	 * check number beetwen max and min
	 * @param (a) - checking number
	 * @param (max) - max number
	 * @param (min) - min number
	 */
	static bool iRange(int a, int max, int min = 0){
		if( ( a <= max ) && ( a >= min ) )
			return true;
		return false;
	}

	/*
	 * generation random number in range min and max
	 * @param (min) - min number
	 * @param (max) - max number
	 */
	static int random(int min, int max){
		int r;

	    std::random_device random_device;
	    std::mt19937 generator( random_device() );

	    std::uniform_int_distribution<> distribution(min, max);
	    r = distribution(generator);

	    return r;
	}

};

#endif