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
*	Test the ringbuffer_iterator function
* 
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main



#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "ring_buffer_class.hpp"
#include "boost/test/unit_test.hpp"


typedef RingNameSpace::Ring_Buffer<int, 100> ringbuffer;
typedef RingNameSpace::Ring_Buffer<int, 0> ringThrow;
/**
*      @brief testing contructor
*      
*/
BOOST_AUTO_TEST_CASE(constructor) {
    // allocate room for 100 elements
    BOOST_REQUIRE_NO_THROW(ringbuffer rb01);

    BOOST_REQUIRE_THROW(ringThrow rb02, std::exception);
    BOOST_REQUIRE_THROW(ringThrow rb03, std::invalid_argument);
}
/**
*      @brief testing pop and push
*      
*/
BOOST_AUTO_TEST_CASE(pop_peek) {
    RingNameSpace::Ring_Buffer<int, 100> rb;

    rb.push_back(2);
    rb.push_back(1);
    rb.push_back(0);

    rb.pop_front();
    BOOST_REQUIRE(rb.front() == 1);
    rb.pop_front();
    rb.pop_front();

    BOOST_REQUIRE_THROW(rb.pop_front(), std::runtime_error);
}

/**
*      @brief testing iterator
*      
*/
BOOST_AUTO_TEST_CASE(iter_test) {
    RingNameSpace::Ring_Buffer<int, 100> test;

    test.push_back(2);
    test.push_back(1);
    test.push_back(0);

    RingNameSpace::ringbuffer_iterator<int, 100> it;

    it = test.begin();
    BOOST_REQUIRE(*it == 2);
    ++it;
    BOOST_REQUIRE(*it == 1);
    ++it;
    BOOST_REQUIRE(*it == 0);
    ++it;
}
