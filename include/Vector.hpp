#pragma once
#include <cstdarg>
#include <exception>
#include <iostream>
#include <iterator>
using namespace std;

namespace containers {
using namespace containers;
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

// TODO: Create operator overloads
class vector {
private:
  // Allocated data for the vector
  unsigned int size;
  // Current vector size
  unsigned int current;
  T *arr;

public:
  // constexpr vector() {
  //   size = 1;
  //   current = 0;
  //   arr = new T[size];
  // }
  // constexpr vector(const int &size_) : size(size_), current(0) {
  //   arr = new T[size];
  // }

  // /**
  //  * @brief Copy Constructor
  //  *
  //  */
  // constexpr vector(const vector &vec_) {
  //   size = vec_.size;
  //   current = vec_.current;
  //   arr = new T[size];
  //   for (int i = 0; i < current; i++) {
  //     arr[i] = vec_.arr[i];
  //   }
  // }

  // /**
  //  * @brief vector(5, 10) = { 10, 10, 10, 10, 10} Creates such a vector.
  //  * \param size_ size of the vector.
  //  \param val_ value which will be stored in the vector.
  //  */
  // constexpr vector(const int &size_, const T &val_)
  //     : size(size_), current(size_) {
  //   arr = new T[size];

  //   for (int i = 0; i < size_; i++) {
  //     arr[i] = val_;
  //   }
  // }

  // vector constructor from array input.
  // template <size_t N> constexpr vector(T (&val)[N]) {
  //   size = sizeof(val) / sizeof(val[0]);
  //   current = 0;
  //   arr = new T[size];

  //   for (; current < size; current++) {
  //     arr[current] = val[current];
  //   }
  // }

  // vector constructor from initializer list.
  template <typename... Ts> constexpr vector(Ts... args) {
    size = sizeof...(Ts);
    current = 0;
    arr = new T[size];
    for (const auto arg : {args...}) {
      arr[current++] = arg;
    }
  }

  /**
   * @brief Constructor from begin and end of the vector.
   *
   */
  template <typename Iterator>
  vector(containers::Iterator<Iterator> begin,
         containers::Iterator<Iterator> end) {
    size = 1;
    current = 0;
    // std::cout << "1111 \n";
    arr = new T[size];
    for (auto it = begin; it != end; it++) {
      // this->push_back(*it);

      if (current == size) {

        T *temp = new T[size * 2];
        for (int i = 0; i < current; i++) {
          temp[i] = arr[i];
        }
        // delete []arr;
        temp[current++] = *it;
        arr = temp;
      } else {
        arr[current++] = *it;
      }
    }
    cout << "\n";
  }
  // ~vector() { delete[] arr; }
  // constexpr unsigned int len() { return current; }
  containers::Iterator<T> begin() { return Iterator(&arr[0]); }
  containers::Iterator<T> end() { return Iterator(&arr[current]); }
  /**
   * @brief Push back data at the end of the vector.
   *
   * @param data data will be pushed back at the end of the vector.
   */
  // void push_back(const T &data) {
  //   if (current == size) {
  //     T *temp = new T[size * 2];
  //     for (int i = 0; i < current; i++) {
  //       temp[i] = arr[i];
  //     }
  //     // // delete previous array
  //     // std::cout << '\n';
  //     // delete[] arr;
  //     temp[current++] = data;
  //     arr = temp;
  //     delete[] temp;
  //   } else {
  //     arr[current++] = data;
  //   }
  // }
};
} // namespace containers