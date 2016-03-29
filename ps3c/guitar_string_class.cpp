/**
 *  @copyright 2016
 *  @file    guitar_string_class.cpp
 *  @author  Duy Truong
 *  @date    3/27/2016  
 *  @version 1.0 
 *  
 *  @brief Contains the implementation for 
 *  the guitar hero class.
 *
 *  @section DESCRIPTION
 *
 *  Implements all the functions of the guitar string.
 *
 */

#include <vector>
#include "guitar_string_class.hpp"

/**
*	@brief RandSeed used to get a random number
*
*/  
class RandSeed {
 public:
     /** 
    *   @brief Constructor that sets the seed
    *  
    *   @param  None
    *   @return N/A
    */
    RandSeed() { seed_ = 12; std::srand(seed_);}
     /** 
    *   @brief  Overloaded operator to get the random value.
    *  
    *   @param  None
    *   @return sf::Int16
    */
    sf::Int16 operator() () {return std::rand() % -32768 + 32768;}
 private:
    // holds seed variable
    sf::Int16 seed_;
};
/**
*	fills the ringbuffer full of zeros based on the frequency
*
*/ 
GuitarHero::GuitarString::GuitarString(double freq):
rb(ceil(44100/freq)), time_(0) {
  for (int x = 0; x < ceil(44100/freq); x++)
    rb.push_back(0);
}

/**
*	Gets vlues from other vector to fill this one
*
*/ 
GuitarHero::GuitarString::GuitarString(std::vector<sf::Int16> & init):
rb(init.size()), time_(0) {
  std::vector<sf::Int16>::iterator it;
  for (it = init.begin(); it != init.end(); it++)
    rb.push_back(*it);
}

/**
*	Fills it with random values using the generate
*
*/ 
void GuitarHero::GuitarString::pluck() {
  RandSeed mygen;
  std::generate(rb.begin(), rb.end(), mygen);
}

/**
 *  Averages the front values and multiplies them by .996
*/ 
void GuitarHero::GuitarString::tic() {
  sf::Int16 front = rb.front();
  rb.pop_front();
  front += rb.front();
  front = (front / 2) * 0.996;
  rb.push_back(front);
  time_++;
}

/**
*	returns the front element
*
*/ 
sf::Int16 GuitarHero::GuitarString::sample() {
  return rb.front();
}

/**
*	Returns the vlue of time.
*
*/ 
int GuitarHero::GuitarString::time() {
  return time_;
}
