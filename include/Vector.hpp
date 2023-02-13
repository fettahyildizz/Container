#pragma once
#include <iostream>


using namespace std;

namespace containers {

	template <typename T>

	struct Iterator {
		
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;  // or also value_type*
		using reference = T&;  // or also value_type&
		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		Iterator& operator++() { m_ptr++; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

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
		T* arr;

	public:
		vector() {
			size = 1;
			current = 0;
			arr = new T[size];
		}
		vector(const int& size_) {
			size = size_;
			current = 0;
			arr = new T[size];
		}
		vector(const int& size_, const T& val_) {
			size = size_;
			arr = new T[size];
			
			for (int i = 0; i < size_; i++) {
				arr[i] = val_;
			}
			current = size_;
		}
		const unsigned int len() {
			return current;
		}
		containers::Iterator<T> begin() { return Iterator(&arr[0]); }
		containers::Iterator<T> end() { return Iterator(&arr[current]); }
		void push_back(const T& data) {
			if (current == size) {
				cout << "DEBUG current" << current << '\n';
				T* temp = new T[size * 2];

				for (int i = 0; i < current; i++) {
					temp[i] = arr[i];
				}
				// delete previous array
				delete[] arr;
				temp[current++] = data;
				cout << "DEBUG current" << current << '\n';
				arr = temp;
			}
			else {
				arr[current++] = data;
			}
		}

	};
}