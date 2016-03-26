/**
*	@copyright 	2016 
	@file 		LFSR.cpp
*	@author		Duy Truong
*	@date		02/15/2016
*	@version 	1.0.0
*	
*
*	@brief	implemetation the LFSR class
*
*	@section DESCRIPTION
*
*	This file implimentation for the function in the LFSR class which are contructor, step, generate, overloaded extractrion operator function.
* 
*/
#include <cmath>
#include <iostream>
#include <string>
#include "lfsr_class.hpp"

/**
* 	@brief Contructor for LFSR class, get the binary number
*
*	@param	seed is the string to use
*	@param	tap is an index or times you want to tap
*	@return N/a
*/
LFSR::LFSR(string seed, int t) {
  data = seed;
  length =  data.size();
  tap = t;
}

/**
*	@brief step function, get the return value, ensurees either 0 or 1. 
*
*	@return int
*/
int LFSR::step() {
  int bit;
  int length = data.size();
  std::string s_bit;
  bit = data.front() ^ data[length -  tap - 1];
  s_bit = std::to_string(bit);
  data.erase(0, 1);
  data = data + s_bit;
  return bit;
}

/**
*	@brief gerate function, runs step on sedd.
*
*	@param steps the resterter k times
*	@return int
*/
int LFSR::generate(int k) {
  int count = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (step() == 1)
      count +=  pow(2, i);
  }
  return count;
}

/**
*	@brief overloaded extraction operator, print the new string
*
*	@param out is an ostream to print
*	@param LFSR is an object of LFSR class
*	@return ostream
*/ 

std::ostream& operator << (std::ostream& out, LFSR& lfsr) {
  out << lfsr.data;
  return out;
}
