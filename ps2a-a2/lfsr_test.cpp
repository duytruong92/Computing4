/**
*	@copyright 2016
*	@file test.cpp
*	@author Duy TRuong
*	@date 02/16/2016
*	@version 1.0.0
*
*	@brief Test the function of the LFSR class does it have error
*
*	@section DESCRIPTion
*
*	Has 3 test case to chec the value of the step and generate function from the LFSR. I use tests seed to check for 4 bits and 32 bits.
*/
#include <iostream>
#include <string>

#include "lfsr_class.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}
BOOST_AUTO_TEST_CASE(fifteenBitsTapAtFive) {
  LFSR l3("010101010101010", 5);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);

  LFSR l4("010101010101010", 5);
  BOOST_REQUIRE(l4.generate(5) == 31);
}

BOOST_AUTO_TEST_CASE(fourBitsTapAtTwo) {
  LFSR l5("1001", 2);
  BOOST_REQUIRE(l5.step() == 1);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 1);

  LFSR l6("1001", 2);
  BOOST_REQUIRE(l6.generate(2) == 2);
}


