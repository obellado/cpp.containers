#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "enable_if.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		
		public:

			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			// typedef std::iterator<pointer> iterator;
			// typedef std::iterator<const_pointer> const_iterator;
			// typedef std::reverse_iterator<iterator> reverse_iterator;
			// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

			explicit vector (const allocator_type& alloc = allocator_type()) : _pointer(0), _size(0), _capacity(0), _alloc(alloc)  {}

			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
				_pointer = _alloc.allocate(n);
            	for (size_type i = 0; i < n; ++i) {
                	_alloc.construct(_pointer + i, val);
				}
			}

			template< class InputIt >
			vector( InputIt first, InputIt last, typename ft::enable_if<std::numeric_limits<InputIt>::value >::type,
        			const Allocator& alloc = Allocator() ) : _alloc(alloc) {
				
				(void)first;
            	(void)last;
			}

			vector (const vector& other) : _size(other._size), _capacity(other._size), _alloc(other._alloc)  {
				_pointer = _alloc.allocate(_size);
            	for (size_type i = 0; i < _size; ++i) {
                	_alloc.construct(_pointer + i, other[i]);
            	}
			}

			virtual ~vector() {
				_deletePointer();
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			vector& operator= (const vector& other) {
				if (this == &other)
					return (*this);
				try {
					_deletePointer();
					_alloc = other._alloc;
					_capacity = other._capacity;
					_size = other._size;
					_pointer = _alloc.allocate(_capacity);
					_copy(0, _size, _pointer, other._pointer);
				} catch (std::bad_alloc & e) {
					throw e;
				}
				return (*this);
			}

			template< class InputIt >
			void assign( InputIt first, InputIt last, typename ft::enable_if<std::numeric_limits<InputIt>::value >::type ) {
				size_type count = _count(first, last);
				std::cout << "ASSIGN template\n";
				if (count > this->max_size())
					throw std::length_error("length_error");
				if (count < _capacity) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_pointer[i]);
				}
				else {
					try {
						pointer newPointer = _alloc.allocate(_size * 2);
						_deletePointer();
						_pointer = newPointer;
						_capacity *= 2;
					} catch (std::bad_alloc & e) {
						throw e;
					}
				}
				size_type i = 0;
				for (; first != last; ++first) {
					_alloc.construct(&_pointer[i++], *first);
				}
				_size = count;
			}

			void assign( size_type count, const T& value ) {
				std::cout << "ASSIGN int int\n";
				if (count > this->max_size())
					throw std::length_error("length_error");
				if (count < _capacity) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_pointer[i]);
				}
				else {
					try {
						pointer newPointer = _alloc.allocate(_size * 2);
						_copy(0, count, newPointer, _pointer);
						_deletePointer();
						_pointer = newPointer;
						_capacity *= 2;
					} catch (std::bad_alloc & e) {
						throw e;
					}
				}
				_copy(0, count, value);
				_size = count;
			}

			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("out_of_range");
				return (_pointer[n]);
			}

			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("out_of_range");
				return (_pointer[n]);
			}

			reference back() {
				return (_pointer[_size - 1]);
			}

			const_reference back() const {
				return (_pointer[_size - 1]);
			}

			size_type capacity() const {
				return (_capacity);
			}
			
			void clear() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_pointer[i]);
				_size = 0;
			}

		// 	iterator begin() {}

		// 	const_iterator begin() const {}

		// const_iterator cbegin() const noexcept {}

		// const_iterator cend() const noexcept {}

		// const_reverse_iterator crbegin() const noexcept {}

		// const_reverse_iterator crend() const noexcept {}

		// 	iterator end() {}

		// 	const_iterator end() const {}

		// 	iterator erase (iterator position) {}
		
		// 	iterator erase (iterator first, iterator last) {}

		// 	reverse_iterator rbegin() {}

		// 	const_reverse_iterator rbegin() const {}

		// 	reverse_iterator rend() {}
		
		// 	const_reverse_iterator rend() const {}

			T* data() {
				if (_size == 0) {
					return NULL;
				}
				return (&_pointer[0]);
			}

			const T* data() const {
				if (_size == 0) {
					return NULL;
				}
				return (&_pointer[0]);
			}

			bool empty() const {
				return (_size == 0);
			}

			reference front() {
				return (_pointer[0]);
			}
		
			const_reference front() const {
				return (_pointer[0]);
			}

			allocator_type get_allocator() const {
				return (_alloc);
			}

		// 	iterator insert( iterator pos, const T& value );

			void insert( iterator pos, size_type count, const T& value ) {
				if (_size + count > this->max_size())
					throw std::length_error("length_error");
				if (_size + count <= _capacity) {
					//
				} else {
					//
				}
				_size += count;
			}

			// template< class InputIt >
			// void insert( iterator pos, InputIt first, InputIt last );

			reference operator[] (size_type n) {
				return (_pointer[n]);
			}

			const_reference operator[] (size_type n) const {
				return (_pointer[n]);
			}

			void pop_back() {
				if (_size > 0) {
					_alloc.destroy(&_pointer[--_size]);
				}
			}

			void push_back(const value_type& val) {
				if (_size == _capacity) {
					try {
						pointer newPointer = _alloc.allocate(_size * 2);
						_copy(0, _size, newPointer, _pointer);
						_deletePointer();
						_pointer = newPointer;
						_capacity *= 2;
					} catch (std::bad_alloc & e) {
						throw e;
					}
				}
				_alloc.construct(&_pointer[_size++], val);
			}

			void reserve (size_type new_cap) {
				if (new_cap > this->max_size())
					throw std::length_error("length_error");
				if (new_cap <= _capacity)
					return ;
				try {
					pointer _newPointer = _alloc.allocate(new_cap);
					_copy(0, _size, _newPointer, _pointer);
					_deletePointer();
					_pointer = _newPointer;
					_capacity = new_cap;
				} catch (std::bad_alloc & e) {
					throw e;
				}
			}

			void resize( size_type count, T value = T() ) {
				if (count > this->max_size())
					throw std::length_error("length_error");
				if (count < _size) {
					for (size_type i = count; i < _size; i++)
						_alloc.destroy(&_pointer[i]);
				} else if (count < _capacity){
					_copy(_size, count, value);
				} else {
					try {
						pointer _newPointer = _alloc.allocate(count * 2);
						_copy(0, _size, _newPointer, _pointer);
						_deletePointer();
						_capacity = count * 2;
						_pointer = _newPointer;
						_copy(_size, count, value);
						_size = count;
					} catch (std::bad_alloc &e) {
						throw e;
					}
				}
			}

			void swap (vector& other) {
				std::swap(this->_pointer, other._pointer);
				std::swap(this->_alloc, other._alloc);
				std::swap(this->_size, other._size);
				std::swap(this->_capacity, other._capacity);
			}


		protected:
			pointer				_pointer;
			size_type			_size;
			size_type			_capacity;
			allocator_type		_alloc;

		private:

			void _deletePointer( void ) {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_pointer[i]);
				if (_capacity != 0)
					_alloc.deallocate(_pointer, _capacity);
			}

			void	_copy(int start, int count, pointer dst, pointer src) {
				for (int i = 0; i < count; i++)
					_alloc.construct(&dst[start + i], src[i]);
			}

			void	_copy(int start, int count, value_type val) {
				for (int i = 0; i < count; i++)
					_alloc.construct(&_pointer[start + i], val);
			}

			template<typename InputIt>
			size_type _count(InputIt first, InputIt last)
			{
				size_type count;

				count = 0;
				for ( ; first != last; ++first)
					count++;
				return (count);
			}
	};


	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
		
	// template <class T, class Alloc>
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}


	// template <class T, class Alloc>
	// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {}

	}

#endif