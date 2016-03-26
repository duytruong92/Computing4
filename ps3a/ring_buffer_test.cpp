/**
*	@copyright 	2016
*	@file 		ring_buffer_test.cpp
*	@author		Duy Truong
*	@date		3/3/2016
*	@version 	1.0.0
*	
*
*	@brief	test ringbuffer class
*
*	@section DESCRIPTION
*
*	Using the boost library to test the ringbuffer class by using unit test.
* 
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include "ring_buffer_class.hpp"
#include "boost/test/unit_test.hpp"
#include "exception"
#include "string"

using RingNameSpace::Ring_Buffer;

/**
*     @brief test case 1 check each function work or not
*     @param N/A
*     @return N/A
*/
BOOST_AUTO_TEST_CASE(RingBufferPushPop) {
  Ring_Buffer<int, 20> ring;
  ring.push_back(10);
  ring.push_back(100);
  BOOST_REQUIRE(ring.front() == 10);
  ring.pop_front();
  BOOST_REQUIRE(ring.front() == 100);
  ring.pop_front();
  BOOST_REQUIRE_THROW(ring.pop_front(), std::runtime_error);
}

/**
*     @brief test case 2 check each function work or not
*     @param N/A
*     @return N/A
*/
BOOST_AUTO_TEST_CASE(ConstructorTest) {
  typedef Ring_Buffer<int, 0> ringbuffer;
  BOOST_REQUIRE_THROW(ringbuffer buff, std::invalid_argument);
}

