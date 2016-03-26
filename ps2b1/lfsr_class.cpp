// Copyright [2016] <Andrew Toufas>
/**
 * LFSR.CPP
 * Andrew Toufas
 * 2/18/16
 * 1.1
 */


#include <iostream>
#include <cmath>
#include <string>
#include "lfsr_class.hpp"

LFSR::LFSR(std::string seed, int tap) {
  // string seed is assigned to seed_
  seed_ = seed;
  // int tap is assigned to the tap_ bit
  tap_ = tap;
}

int LFSR::step() {
  // cont stores the exclusive or outcome
  bool cont = seed_[0] ^ seed_[tap_];
  // temp bit
  std::string bit;
  // temp int bit2
  int bit2;
  // if statement to check if cont is '0' or '1'
  if (cont) {
      // if cont, bit is assigned '1'
      bit = "1";
      // if cont, erase head of the string to shift seed
      seed_.erase(0, 1);
      // if cont, add 1 to the end of the seed
      seed_ += bit;
      // if cont, temp bit2 is assigned 1
      bit2 = 1;
      // else everything is 0 or '0'
    } else {
    // if not cont, temp bit '0'
      bit = "0";
      // if not cont erase head to shift string
      seed_.erase(0, 1);
      // if not cont, add '0' to the string
      seed_+= bit;
      // if not cont, set temp bit2 to 0
      bit2 = 0;
    }
  // return either 0 or 1 based on the above if statement
  return bit2;
}


int LFSR::generate(int k) {
  // Temp int set to 0
  int generatedNum = 0;
  // For loop to loop through the seed
  for (int i = k-1; i >= 0; i--) {
    // if step, then do the if statement
      if (step() == 1) {
       // if step, compute i to the power of 2 and add to generatednum
          generatedNum = generatedNum + pow(2, i);
         }
    }
  // return the entire sum
  return generatedNum;
}

std::ostream & operator << (std::ostream & out, LFSR & lfsr) {
  // extract the seed to out
  out << lfsr.seed_;
  // return out
  return out;
}

