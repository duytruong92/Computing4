// Copyright[2016] <Andrew Toufas>
/**
 *Copyright 2016
 * Class that helps implement Lift feedback shift register
 */
#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <string>

class LFSR{
 public:
  /**
   * @brief Constructor for LFSR
   * @param string seed is the seed that we are generating from
   *        int tap is the tap bit
   * @returns nothing
   */
  LFSR(std::string seed, int tap);
  /**
   * @brief step function to step through the seed
   * @param n/a
   * @ returns 0 or 1 based on the exclusive or operation
   */
  int step();
  /**
   * @brief Generates the number from the seed
   * @param int k shows how many bits you want to be accounted for in the seed
   * @returns generated number from seed
   */
  int generate(int k);
  /**
   * @brief Overloads extraction operator
   * @param out is what is extracted to, lfsr is the seed being extracted
   * @returns out with the extracted string
   */
  friend std::ostream & operator << (std::ostream &out, LFSR & lfsr);

 private:
  std::string seed_;  ///< String that stores the seed
  int tap_;           ///< Tab Bit
};

#endif
