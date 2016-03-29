/**
 *  @copyright 2016
 *  @file    guitar_string_class.hpp
 *  @author  Duy Truong
 *  @date    3/27/2016  
 *  @version 1.0 
 *  
 *  @brief Declaration of the Guitar String class
 *
 *  @section DESCRIPTION
 *
 *  This class contains the declarations of the 
 *  string guitar hero class.
 *
 */
#ifndef GUITAR_STRING_CLASS_HPP
#define GUITAR_STRING_CLASS_HPP

#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "ring_buffer_class.hpp"

 /**
*  @brief Namespace for the Guitar Hero class
*/ 
namespace GuitarHero {
class GuitarString {
 public:
     /** 
    *   @brief  Explicit constructor that takes the frquency 
    *  
    *   @param  double value
    *   @return N/A
    */
    explicit GuitarString(double freq);
     /** 
    *   @brief  Constructor that tskes a vector
    *  
    *   @param  std::vector of type int16
    *   @return N/A
    */
    explicit GuitarString(std::vector<sf::Int16> & init);
     /** 
    *   @brief  Puts the random values into the strings
    *  
    *   @param  None 
    *   @return None
    */
    void pluck();
     /** 
    *   @brief  Gets the first two values and adds them and divide by 2,
    *           then multiply by .996
    *  
    *   @param  None
    *   @return None
    */
    void tic();
     /** 
    *   @brief  Helper function to get the front .
    * 
    *   @param  None
    *   @return front of the vectr
    */
    sf::Int16 sample();
     /** 
    *   @brief  Helper function, return the value of time
    *  
    *   @param  None
    *   @return time
    */
    int time();

 private:
    ring_buffer<sf::Int16> rb;  ///< ringbuffer
    int time_;   ///< contain the current time
};
}  // namespace GuitarHero
#endif
