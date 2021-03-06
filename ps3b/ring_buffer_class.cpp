/**
*	@copyright 	2016
*	@file 		ring_bufferclass.cpp
*	@author		Duy Truong
*	@date		3/3/2016
*	@version 	1.0.0
*	
*
*	@brief	Define the ringbuffer class
*
*	@section DESCRIPTION
*
*	Declearation the ringbuffer class and include the library for the function. define the private value is size, capacity, size, begin_.
* 
*/

#ifndef RING_BUFFER_CLASS_C
#define RING_BUFFER_CLASS_C

#include "ring_buffer_class.hpp"
#include <stdexcept>
#include <iostream>
/**
*      @brief Default Constructor
*      @param N/A
*      @return N/A
*/
template <typename Types, int capacity>
RingNameSpace::Ring_Buffer<Types, capacity>::Ring_Buffer() {
    if (capacity <= 0)
        throw std::invalid_argument("The capacity is invalid");
    buffer_ = new Types[capacity];
    if (buffer_ == NULL)
        throw std::invalid_argument("");
    capacity_ = capacity;
    begin_ = 0;
    size_ = 0;
}
/**
*     @brief Default Deconstructor
*     @param N/A
*     @return N/A
*/
template <typename Types, int capacity>
RingNameSpace::Ring_Buffer<Types, capacity>::~Ring_Buffer() {
    delete []buffer_;
}
/**
*     @brief Adds T item to the end of the RingBuffer
*     @param T item
*     @return N/A
*/
template <typename Types, int capacity>
void RingNameSpace::Ring_Buffer<Types, capacity>::push_back(Types val) {
    if (isFull() == true)
        throw std::runtime_error("The ringbuffer is Full");
    int end = (begin_+size_)%capacity_;
    buffer_[end] = val;
    size_+=1;
}
/**
*     @brief remove the front element
*     @param N/A
*     @return N/A
*/
template <typename Types, int capacity>
void RingNameSpace::Ring_Buffer<Types, capacity>::pop_front() {
    if (empty() == true)
        throw std::runtime_error("No Element in the array");
    if (begin_+1 == capacity_)
        begin_ = 0;
    else
        begin_ += 1;
    size_ -= 1;
}
/** 
*   @brief  Return the first element
*   @param  None
*   @return the first element
*/
template <typename Types, int capacity>
Types & RingNameSpace::Ring_Buffer<Types, capacity>::front() {
    if (empty() == true)
        throw std::runtime_error("The Ringbuffer is empty");
    return buffer_[begin_];
}
/** 
*   @brief  Check the queue is full or not    
*   @param  None
*   @return True or False
*/
template <typename Types, int capacity>
bool RingNameSpace::Ring_Buffer<Types, capacity>::isFull() {
    if (size_ >= capacity_)
        return true;
    else
        return false;
}
/** 
*   @brief  Check the queue is empty or not  
*   @param  None
*   @return True or False
*/
template <typename Types, int capacity>
bool RingNameSpace::Ring_Buffer<Types, capacity>::empty() {
    if (size_ <= 0)
        return true;
    else
        return false;
}
/** 
*   @brief  Return the address of the first element
*   @param  None
*   @return Address of the first element
*/    
template <typename Types, int capacity>
RingNameSpace::ringbuffer_iterator<Types, capacity>
RingNameSpace::Ring_Buffer<Types, capacity>::begin() {
    ringbuffer_iterator<Types, capacity> begin(&buffer_[begin_], this);
    return begin;
}

/** 
*   @brief  Returns the address of the Last element   
*   @param  None
*   @return Address
*/
template <typename Types, int capacity>
RingNameSpace::ringbuffer_iterator<Types, capacity>
RingNameSpace::Ring_Buffer<Types, capacity>::end() {
    ringbuffer_iterator<Types,
capacity> end(&buffer_[(begin_+size_)%capacity_], this);
    return end;
}

/** 
*   @brief  Returns size of array   
*   @param  None
*   @return int
*/ 
template <typename Types, int capacity>
int RingNameSpace::Ring_Buffer<Types, capacity>::size() {
    return size_;
}
/**
*      @brief Default Constructor
*      @param N/A
*      @return N/A
*/   
template <typename Types, int capacity>
RingNameSpace::ringbuffer_iterator<Types, capacity>::ringbuffer_iterator() {
}

/**
*      @brief overloading Constructor
*      @param N/A
*      @return N/A
*/   
template <typename Types, int capacity>
RingNameSpace::ringbuffer_iterator<Types, capacity>
::ringbuffer_iterator(Types* pT, Ring_Buffer<Types, capacity> * pBuff) {
    this->iter_ = pT;
    this->Array = pBuff;
}
/**
*      @brief overloading operator "!="
*      @param *T iENd
*      @return True or False
*/

template <typename Types, int capacity>
bool RingNameSpace::ringbuffer_iterator
<Types, capacity>::operator!=(Types * iEnd) {
    if (iter_ != iEnd) {
        return true;
    }
        return false;
}
/**
*      @brief overloading operator "++"
*      @param N/A
*      @return N/A
*/

template <typename Types, int capacity>
void RingNameSpace::ringbuffer_iterator<Types, capacity>::operator++() {
    if (iter_ == NULL)
    throw std::runtime_error("Nothing in the array");
  if (iter_ == &Array->buffer_[capacity-1])
    iter_ = NULL;
  iter_++;
}

/**
*      @brief overloading operator "*"
*      @param N/A
*      @return T
*/

template <typename Types, int capacity>
Types RingNameSpace::ringbuffer_iterator<Types, capacity>::operator*() {
    if (iter_ == NULL)
    throw std::runtime_error("Nothing in the array");
    return *iter_;
}

#endif




