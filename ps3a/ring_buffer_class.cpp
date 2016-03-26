/**
*	@copyright 	2016
*	@file 		ring_buffer_class.cpp
*	@author		Duy Truong
*	@date		3/3/2016
*	@version 	1.0.0
*	
*
*	@brief	Define the ringbuffer class
*
*	@section DESCRIPTION
*
*	Declearation the ringbuffer class and include the library for the function. define the private value is size, capacity, size, begin.
* 
*/

#ifndef RING_BUFFER_CPP
#define RING_BUFFER_CPP
#include "ring_buffer_class.hpp"
#include <stdexcept>


/**
*      @brief Default Constructor
*      @param N/A
*      @return N/A
*/
template <typename T, int capacity>
RingNameSpace::Ring_Buffer<T, capacity>::Ring_Buffer() {
  if (capacity <= 0) {
    throw std::invalid_argument("Capacity has to be greater than 0");
  }
  capacity_ = capacity;
  buffer = new T[capacity];
  if (buffer == NULL) {
    throw std::invalid_argument("Buffer memory did not allocate correctly");
  }
  begin = 0;
  size = 0;
}

/**
*     @brief Default Deconstructor
*     @param N/A
*     @return N/A
*/
template <typename T, int capacity>
RingNameSpace::Ring_Buffer<T, capacity>::~Ring_Buffer() {
  delete buffer;
}

/**
*     @brief Returns the size of the RingBuffer
*     @param N/A
*     @return int
*/
template <typename T, int capacity>
int RingNameSpace::Ring_Buffer<T, capacity>::getSize() {
  return size;
}


/**
*     @brief Adds T item to the end of the RingBuffer
*     @param T item
*     @return N/A
*/
template <typename T, int capacity>
void RingNameSpace::Ring_Buffer<T, capacity>::push_back(T item) {
  int end;
  if ( size == 0 ) {
    end = 0;
  } else {
    end = (begin + size)%capacity_;
    if (end >= capacity) {
      throw std::runtime_error("Can't push, buffer full");
    }
  }
  size++;
  buffer[end] = item;
}

/**
*     @brief remove the front element
*     @param N/A
*     @return N/A
*/
template <typename T, int capacity>
void RingNameSpace::Ring_Buffer<T, capacity>::pop_front(void) {
  if (size == 0) {
    throw std::runtime_error("Can't pop, buffer empty");
  }
  if (begin+1 == capacity_) {
    begin = 0;
  } else {
    begin++;
  }
  size--;
}

/**
*     @brief Returns the first element
*     @param N/A
*     @return T
*/
template <typename T, int capacity>
T RingNameSpace::Ring_Buffer<T, capacity>::front() {
  if (size== 0) {
    throw std::runtime_error("Nothing in the front, buffer empty");
  }
  return buffer[begin];
}

/**
*     @brief  Returns the last element
*     @param N/A
*     @return N/A
*/
template <typename T, int capacity>
T RingNameSpace::Ring_Buffer<T, capacity>::end() {
  if (size== 0) {
    throw std::runtime_error("Nothing in the back, buffer empty");
  }
  int end = (begin + size)%capacity_;
  return buffer[end];
}

/**
*      @brief Not implimented for the iterator 
*      @param N/A
*      @return T
*/
template <typename T, int capacity>
T RingNameSpace::Ring_Buffer<T, capacity>::for_each() {
}

/**
*     @brief Not Implemented = Operator for a non copyable constructor
*     @param N/A
*     @return N/A
*/
template <typename T, int capacity>
T* RingNameSpace::Ring_Buffer<T, capacity>::find(T item) {
}

#endif
