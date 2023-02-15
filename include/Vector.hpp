#pragma once
#include <cstdarg>
#include <iostream>
using namespace std;

namespace containers {

template <typename T>

struct Iterator {

  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;   // or also value_type*
  using reference = T &; // or also value_type&
  Iterator(pointer ptr) : m_ptr(ptr) {}

  reference operator*() const { return *m_ptr; }
  pointer operator->() { return m_ptr; }
  Iterator &operator++() {
    m_ptr++;
    return *this;
  }
  Iterator operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  friend bool operator==(const Iterator &a, const Iterator &b) {
    return a.m_ptr == b.m_ptr;
  };
  friend bool operator!=(const Iterator &a, const Iterator &b) {
    return a.m_ptr != b.m_ptr;
  };

private:
  pointer m_ptr;
};

template <typename T>

class vector {
private:
  // Allocated data for the vector
  unsigned int size;
  // Current vector size
  unsigned int current;
  T *arr;

public:
  vector() {
    size = 1;
    current = 0;
    arr = new T[size];
  }
  vector(const int &size_) : size(size_) {
    current = 0;
    arr = new T[size];
  }
  // vector(5, 10) = { 10, 10, 10, 10, 10} Creates such a vector.
  vector(const int &size_, const T &val_) : size(size_), current(size_) {
    arr = new T[size];

    for (int i = 0; i < size_; i++) {
      arr[i] = val_;
    }
  }
  // template <typename T2> 
  vector(T val, ...) {
    size = 1;
    current = 0;
    // cout << "sizeof: " << sizeof...();
    va_list args;
    va_start(args, val);
    T arg = va_arg(args, T);
    // cout << arg[0] << '\n';
    // cout << arg << '\n';
    for (int i=0 ; i<7; i++){
      cout << "i: "<< i << ": " <<arg << '\n';
      arg = va_arg(args, T);
    }
    cout << "end\n";
    // while (arg != '\0') {
    //   cout << arg << '\n';
    // }
    va_end(args);
  }

  ~vector() { delete[] arr; }
  const unsigned int len() { return current; }
  containers::Iterator<T> begin() { return Iterator(&arr[0]); }
  containers::Iterator<T> end() { return Iterator(&arr[current]); }
  void push_back(const T &data) {
    if (current == size) {
      T *temp = new T[size * 2];

      for (int i = 0; i < current; i++) {
        temp[i] = arr[i];
      }
      // delete previous array
      delete[] arr;
      temp[current++] = data;
      arr = temp;
    } else {
      arr[current++] = data;
    }
  }
};
} // namespace containers