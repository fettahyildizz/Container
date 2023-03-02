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
		using pointer = T*;   // or also value_type*
		using reference = T&; // or also value_type&
		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		Iterator& operator++() {
			m_ptr++;
			return *this;
		}
		Iterator operator++(int) {
			Iterator tmp = *this;
			++(*this);
			return tmp;
		}
		Iterator& operator+(const T& range) {
			for (int i = 0; i < range; i++) {
				m_ptr++;
			}
			return *this;
		}
		Iterator& operator-(const T& range) {
			for (int i = 0; i < range; i++) {
				m_ptr--;
			}
			return *this;
		}

		friend bool operator==(const Iterator& a, const Iterator& b) {
			return a.m_ptr == b.m_ptr;
		};
		friend bool operator!=(const Iterator& a, const Iterator& b) {
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
		size_t capacity;
		// Current vector capacity
		size_t size;
		T* arr;

	public:
		constexpr vector() {
			capacity = 1;
			size = 0;
			arr = new T[capacity];
		}
		const vector(const int& capacity_) : capacity(capacity_), size(0) {
			arr = new T[capacity];
		}

		/**
		 * @brief Copy Constructor
		 *
		 */
		constexpr vector(const vector& vec_) {
			capacity = vec_.capacity;
			size = vec_.size;
			arr = new T[capacity];
			for (int i = 0; i < size; i++) {
				arr[i] = vec_.arr[i];
			}
		}

		/**
		 * @brief vector(5, 10) = { 10, 10, 10, 10, 10} Creates such a vector.
		 * \param capacity_ capacity of the vector.
		 \param val_ value which will be stored in the vector.
		 */
		const vector(const int& capacity_, const T& val_)
			: capacity(capacity_), size(capacity_) {
			arr = new T[capacity];

			for (int i = 0; i < capacity_; i++) {
				arr[i] = val_;
			}
		}

		// vector constructor from array input.
		template <size_t N> constexpr vector(T(&val)[N]) {
			capacity = sizeof(val) / sizeof(val[0]);
			size = 0;
			arr = new T[capacity];

			for (; size < capacity; size++) {
				arr[size] = val[size];
			}
		}

		// vector constructor from initializer list.
		template <typename... Ts> const vector(Ts... args) {
			capacity = sizeof...(Ts);
			size = 0;
			arr = new T[capacity];
			for (const auto arg : { args... }) {
				arr[size++] = arg;
			}
		}

		/**
		 * @brief Constructor from begin and end of the vector.
		 *
		 */
		template <typename Iterator>
		vector(containers::Iterator<Iterator> begin,
			containers::Iterator<Iterator> end) {
			capacity = 1;
			size = 0;
			arr = new T[capacity];
			for (auto it = begin; it != end; it++) {
				this->push_back(*it);
			}
		}
		~vector() { delete[] arr; }
		const unsigned int len() { return size; }

		/**
		* @brief Operator for add
		*/
		vector operator + (const vector& obj) {
			int capacity_ = size > obj.size ? size : obj.size;
			vector temp(capacity_);
			if (size > obj.size) {
				for (int i = 0; i < obj.size; i++) {
					temp.push_back(obj.arr[i] + arr[i]);
				}
				for (int i = obj.size; i < size; i++) {
					temp.push_back(arr[i]);
				}
			}
			else if (size == obj.size) {
				for (int i = 0; i < obj.size; i++) {
					temp.push_back(obj.arr[i] + arr[i]);
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					temp.push_back(obj.arr[i] + arr[i]);
				}
				for (int i = size; i < obj.size; i++) {
					temp.push_back(obj.arr[i]);
				}
			}

			return temp;
		}
		/**
		* @brief Operator for subtraction
		*/
		vector operator - (const vector& obj) {
			int capacity_ = size > obj.size ? size : obj.size;
			vector temp(capacity_);
			if (size > obj.size) {
				for (int i = 0; i < obj.size; i++) {
					temp.push_back(arr[i] - obj.arr[i]);
				}
				for (int i = obj.size; i < size; i++) {
					temp.push_back(arr[i]);
				}
			}
			else if (size == obj.size) {
				for (int i = 0; i < obj.size; i++) {
					temp.push_back(arr[i] - obj.arr[i]);
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					temp.push_back(arr[i] - obj.arr[i]);
				}
				for (int i = size; i < obj.size; i++) {
					temp.push_back(obj.arr[i]);
				}
			}

			return temp;
		}

		const T operator[](const size_t& index) const {
			if ((index >= size) || (index < 0))
				throw out_of_range("Accessing out of bounds.");
			else return arr[index];
		}
		T& operator[](const size_t& index) {
			if ((index >= size) || (index < 0))
				throw out_of_range("Accessing out of bounds.");
			else return arr[index];

		}
		/**
		 * @brief Push back data at the end of the vector.
		 *
		 * @param data data will be pushed back at the end of the vector.
		 */
		void push_back(const T& data) {
			if (size == capacity) {
				capacity = capacity * 2;
				T* temp = new T[capacity];
				for (int i = 0; i < size; i++) {
					temp[i] = arr[i];
				}
				// // delete previous array since arr = temp is equal to arr points to temp's pointers pointing memory.
				delete[] arr;
				temp[size++] = data;
				arr = temp;
			}
			else {
				arr[size++] = data;
			}
		}

		/**
		* @brief Returns a reference to the element at position n in the vector.
		*/
		const T at(const size_t& index) const {
			if ((index >= size) || (index < 0))
				throw out_of_range("Out of range error. Accessing " + index);
			else return arr[index];
		}

		T& at(const size_t& index) {
			if ((index >= size) || (index < 0))
				throw out_of_range("Out of range error. Accessing " + index);
			else return arr[index];
		}

		T back() const {
			return arr[size - 1];
		}

		size_t _capacity_() const {
			return capacity;
		}
		size_t _size_() const {
			return size;
		}
		void clear() {
			T* temp = new T[capacity];
			size = 0;
			delete[] arr;
			arr = temp;
		}

		T* data() {
			return arr;
		}

		/*void emplace(containers::Iterator<T>& it_, const T& val_) {
			if (size == capacity) {
				capacity *= 2;
			}
			T* temp = new T[capacity];
			size_t idx = 0;
			for (auto it = begin(); it != it_; it++) {
				temp[idx++] = *it;
			}

			temp[idx++] = val_;
			for (auto it = it_ ; it != end(); it++) {

				temp[idx++] = *it;
			}
			size = idx;
			delete[]arr;
			arr = temp;
		}*/

		//template <typename Iterator>
		//void emplace(containers::Iterator<Iterator> begin_, const T& val_) {
		//	size_t idx = 0;
		//	bool increase_capacity = false;	
		//	if (size == capacity) {
		//		increase_capacity = true;
		//		
		//	}
		//	//cout << " *begin_: " << *begin_ << '\n';
		//	T removed_val = *begin_;
		//	*begin_++ = val_;
		//	//begin_++;
		//				
		//		
		//	for (auto it = begin_; it != end(); it++) {
		//		
		//		//cout << " *it: " << *it << '\n';
		//		T removed_val2 = *it;
		//		*it = removed_val;
		//		removed_val = removed_val2;
		//	}
		//	if (increase_capacity == true) {
		//		capacity *= 2;
		//		T* temp = new T[capacity];
		//		for (int i = 0; i < size; i++) {
		//			temp[i] = arr[i];
		//		}
		//		// // delete previous array since arr = temp is equal to arr points to temp's pointers pointing memory.
		//		delete[] arr;
		//		arr = temp;
		//	}
		//	*end() = removed_val;
		//	size++;
		//}
		template <typename T2>
		template <typename... ARGS>
		void emplace(const containers::Iterator<T2>* pos, ARGS&&... args) {
			const size_t dist = pos - begin();

			if (dist == capacity)
			{
				//emplace_back(T(std::forward<T>(args)...));
			}
			else
			{
				if (size == capacity)
				{
					capacity *= 2;
					T* temp = new T[capacity];
							for (int i = 0; i < size; i++) {
								temp[i] = arr[i];
							}
							// // delete previous array since arr = temp is equal to arr points to temp's pointers pointing memory.
							delete[] arr;
							arr = temp;
				}
				std::move_backward(begin() + dist, end(), end() + 1);
				iterator iter = &arr[dist];
				*iter = std::move(args);
				cout << "*iter: " << *iter << '\n';
			}
		}
		
		containers::Iterator<T> cbegin() const { return Iterator(&arr[0]); }
		containers::Iterator<T> begin() { return Iterator(&arr[0]); }
		containers::Iterator<T> cend() const { return Iterator(&arr[size]); }
		containers::Iterator<T> end() { return Iterator(&arr[size]); }

	};
} // namespace containers