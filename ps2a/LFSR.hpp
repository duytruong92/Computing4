/**
*	@copytight 	2016
*	@file 		LFSR.cpp
*	@author		Duy Truong
*	@date		02/15/2016
*	@version 	1.0.0
*	
*
*	@brief	Define the LFSR class
*
*	@section DESCRIPTION
*
*	Declearation the LFSR class and include the library for the function. The seed and seed are strings, length and tap is int value.
* 
*/
#ifndef LFSR_HPP_
#define LFSR_HPP_

#include <iostream>
#include <string>

using namespace std;
/**
* 	@brief Class is an randomsizes of seed using xoe on seed.
*/
class LFSR 
{
 public:
	/**
	* 	@brief Contructor for LFSR class, get the binary number
	*
	*	@param	seed is the string to use
	*	@param	tap is an index or times you want to tap
	*	@return N/a
	*/
        LFSR(string seed, int t);
	/**
	*	@brief step function, get the return value, ensurees either 0 or 1. 
	*
	*	@return int
	*/
        int step();
 	/**
	*	@brief gerate function, runs step on sedd.
	*
	*	@param steps the resterter k times
	*	@return int
	*/
		int generate(int k);
	/**
	*	@brief overloaded extraction operator, print the new string
	*
	*	@param out is an ostream to print
	*	@param LFSR is an object of LFSR class
	*	@return ostream
	*/ 
        friend ostream& operator << (ostream& out, LFSR& lfsr);

 private:
	int length;		///< length of the string
	int tap;		///< tap location (index)
	string data;	///< string kepp the data of seed
	
};

#endif
