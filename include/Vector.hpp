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
  Iterator &operator+(const T& range) {
    for (int i = 0; i < range; i++){
      m_ptr++;
    }
    return *this;
  }
  Iterator &operator-(const T& range) {
    for (int i = 0; i < range; i++){
      m_ptr--;
    }
    return *this;
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
  constexpr vector() {
    size = 1;
    current = 0;
    arr = new T[size];
  }
  const vector(const int &size_) : size(size_), current(0) {
    arr = new T[size];
  }

  /**
   * @brief Copy Constructor
   *
   */
  constexpr vector(const vector &vec_) {
    size = vec_.size;
    current = vec_.current;
    arr = new T[size];
    for (int i = 0; i < current; i++) {
      arr[i] = vec_.arr[i];
    }
  }

  /**
   * @brief vector(5, 10) = { 10, 10, 10, 10, 10} Creates such a vector.
   * \param size_ size of the vector.
   \param val_ value which will be stored in the vector.
   */
  const vector(const int &size_, const T &val_)
      : size(size_), current(size_) {
    arr = new T[size];

    for (int i = 0; i < size_; i++) {
      arr[i] = val_;
    }
  }

  // vector constructor from array input.
  template <size_t N> constexpr vector(T (&val)[N]) {
    size = sizeof(val) / sizeof(val[0]);
    current = 0;
    arr = new T[size];

    for (; current < size; current++) {
      arr[current] = val[current];
    }
  }

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
    arr = new T[size];
    for (auto it = begin; it != end; it++) {
      this->push_back(*it);
    }
  }
  ~vector() { delete[] arr; }
  constexpr unsigned int len() { return current; }
  unsigned int _size_() { return size; }
  /**
  * @brief Operator for add
  */
  vector operator + (const vector& obj) {
      int size_ = current > obj.current ? current : obj.current;
      vector temp(size_);
      if (current > obj.current) {
          for (int i = 0; i < obj.current; i++) {
              temp.push_back(obj.arr[i] + arr[i]);
          }
          for (int i = obj.current; i < current; i++) {
              temp.push_back(arr[i]);
          }
      }
      else if (current == obj.current) {
          for (int i = 0; i < obj.current; i++) {              
              temp.push_back(obj.arr[i] + arr[i]);
          }
      }
      else {
          for (int i = 0; i < current; i++) {
              temp.push_back(obj.arr[i] + arr[i]);
          }
          for (int i = current; i < obj.current; i++) {
              temp.push_back(obj.arr[i]);
          }
      }
      
      return temp;
  }
  /**
  * @brief Operator for subtraction
  */
  vector operator - (const vector& obj) {
      int size_ = current > obj.current ? current : obj.current;
      vector temp(size_);
      if (current > obj.current) {
          for (int i = 0; i < obj.current; i++) {
              temp.push_back(arr[i] - obj.arr[i]);
          }
          for (int i = obj.current; i < current; i++) {
              temp.push_back(arr[i]);
          }
      }
      else if (current == obj.current) {
          for (int i = 0; i < obj.current; i++) {
              temp.push_back(arr[i] - obj.arr[i]);
          }
      }
      else {
          for (int i = 0; i < current; i++) {
              temp.push_back(arr[i] - obj.arr[i]);
          }
          for (int i = current; i < obj.current; i++) {
              temp.push_back(obj.arr[i]);
          }
      }

      return temp;
  }

  const T operator[](const size_t& i) const { return arr[i]; }
  T& operator[](const size_t& i) { return arr[i]; }
  /**
   * @brief Push back data at the end of the vector.
   *
   * @param data data will be pushed back at the end of the vector.
   */
  void push_back(const T &data) {
    if (current == size) {
      size = size * 2;
      T *temp = new T[size];
      for (int i = 0; i < current; i++) {
        temp[i] = arr[i];
      }
      // // delete previous array since arr = temp is equal to arr points to temp's pointers pointing memory.
      delete[] arr;
      temp[current++] = data;
      arr = temp;
    } else {
      arr[current++] = data;
    }
  }

  /**
  * @brief Returns a reference to the element at position n in the vector.
  */
  const T at(const size_t& index) const {
      //try {
          cout <<"aaa: " << arr[index] << '\n';
          return arr[index];
      /*}
      catch (const out_of_range& oor) {
          cerr << "Out of range error: " << oor.what() << '\n';
      }*/
  }

  T &at(const size_t& index)  {
      cout << "bbb: " << arr[index] << '\n';
      return arr[index];
      /* try {
          cout << "bbb: " << arr[index] << '\n';
          return arr[index];
      }
      catch (const out_of_range& oor) {
          cerr << "Out of range error: " << oor.what() << '\n';
      }*/
  }

  containers::Iterator<T> begin() { return Iterator(&arr[0]); }
  containers::Iterator<T> end() { return Iterator(&arr[current]); }

};
} // namespace containers