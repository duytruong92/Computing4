/**
 *  @copyright 2016
 *  @file    ring_buffer_class.cpp
 *  @author  Duy Truong
 *  @date    3/27/2016  
 *  @version 1.0 
 *  
 *  @brief Implementation of the ring_buffer_class.
 *
 *  @section DESCRIPTION
 *
 *  This file contains the implementation of the 
 *  required functions within the ringbuffer class,
 *  including the constructor, destructor, pop_front, push_back, 
 *  and front functions. The class is also a non copyable class.
 *
 */
#ifndef RING_BUFFER_CPP
#define RING_BUFFER_CPP

#include <stdexcept>
#include "ring_buffer_class.hpp"

namespace GuitarHero {

  template<typename T>
  ring_buffer<T>::ring_buffer(int capacity):capacity_(capacity) {
    // Throw an exception of the capacity is -ve or zero
    if (capacity_ <= 0) {
      throw std::invalid_argument("invalid capacity: ");
    }
    buffer_ = new T[capacity_];
    size_ = 0;
    begin_ = 0;
  }

  template<typename T>
  ring_buffer<T>::~ring_buffer() {
    delete [] buffer_;
  }


  template<typename T>
  void ring_buffer<T>::push_back(T element) {
    // Getting the index of the end element
    int end = (size_ + begin_) % capacity_;
    // Check if the buffer is full or not
    if (size_ == capacity_) {
      throw std::runtime_error("Trying to add to a full buffer");
    } else {
      buffer_[end] = element;
      size_++;
    }
  }

  template<typename T>
  void ring_buffer<T>::pop_front() {
    // Check if the buffer is empty or not
    // if empty then throw an exeption
    if (empty()) {
      throw std::runtime_error("Trying to remove from an empty buffer");
    } else {
      // Buffer is not empty and you can read
      if (begin_ == (capacity_-1)) {
        begin_ = 0;
      } else {
        begin_++;
      }
      size_--;
    }
  }

  template<typename T>
  int ring_buffer<T>::size() const {
    return size_;
  }

  template<typename T>
  bool ring_buffer<T>::empty() const {
    return size_ == 0;
  }

  template<typename T>
  T& ring_buffer<T>::front() const {
    // Check if the buffer is empty or not
    // Cannot read from an empty buffer
    if (empty()) {
      throw std::runtime_error("Trying to remove from an empty buffer");
    }
    return buffer_[begin_];
  }

  template<typename T>
  ring_buffer_itr<T>::ring_buffer_itr(const ring_buffer<T> & buffer, int offset)
    :buffer_(buffer), offset_(offset) {
  }

  template<typename T>
  ring_buffer_itr<T> & ring_buffer_itr<T>::operator++() {
    // Check if iterator reached the end of the buffer or not
    if (offset_ == buffer_.size_) {
      throw std::runtime_error("End of buffer");
    }
    // if not then preincrement the iterator
    ++offset_;
    return *this;
  }

  template<typename T>
  bool ring_buffer_itr<T>::operator==(const ring_buffer_itr<T> & other) {
    // Check if the two iterators are equal.
    // If both are equal then they should be holding a reference
    // to the same ring buffer and also has the same offset
    return (&other.buffer_ == &buffer_ && other.offset_ == offset_);
  }

  template<typename T>
  bool ring_buffer_itr<T>::operator!=(const ring_buffer_itr<T> & other) {
    return !(*this == other);
  }

  template<typename T>
  T& ring_buffer_itr<T>::operator*() {
    // check if the iterator is pointing to the end
    int index = (buffer_.begin_ + offset_)%buffer_.capacity_;
    if (offset_ == buffer_.size_) {
      throw std::runtime_error("End of the buffer");
    }
    return buffer_.buffer_[index];
  }
}  // namespace GuitarHero

#endif  // RING_BUFFER_CPP
