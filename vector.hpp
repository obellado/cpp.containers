#include <iostream>
#include <memory>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
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

			// typedef ft::_iterator<pointer> iterator;
			// typedef ft::_iterator<const_pointer> const_iterator;
			// typedef ft::_reverse_iterator<iterator> reverse_iterator;
			// typedef ft::_reverse_iterator<const_iterator> const_reverse_iterator;

			explicit vector (const allocator_type& alloc = allocator_type()) : _pointer(0), _size(0), _capacity(0), _alloc(alloc)  {}

			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) {
				_pointer = vectorAlloc.allocate(n);
            	for (size_type i = 0; i < n; ++i) {
                	_alloc.construct(vectorBegin + i, val);
				}
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				(void)first;
            	(void)last;
			}

			vector (const vector& x) : _size(other._size), _capacity(other._size), _alloc(other._alloc)  {
				_pointer= vectorAlloc.allocate(_size);
            	for (size_type i = 0; i < _size; ++i) {
                	_alloc.construct(_pointer + i, other[i]);
            	}
			}

			virtual ~vector() {
				for (size_type ji = 0; i < _size; i++)
					_alloc.destroy(&pointer[i]);
				if (_capacity != 0)
					_alloc.deallocate(pointer, _capacity);
			}

			vector& operator= (const vector& other) {}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {}

			void assign (size_type n, const value_type& val) {}

			reference at (size_type n) {}

			const_reference at (size_type n) const {}

			reference back() {}

			const_reference back() const {}

			iterator begin() {}

			const_iterator begin() const {}

			size_type capacity() const {}

		// const_iterator cbegin() const noexcept {}

		// const_iterator cend() const noexcept {}

			void clear() {}

		// const_reverse_iterator crbegin() const noexcept {}

		// const_reverse_iterator crend() const noexcept {}

		// value_type* data() noexcept {}
		// const value_type* data() const noexcept {}

		// template <class... Args>
		// iterator emplace (const_iterator position, Args&&... args) {}

		// template <class... Args>
		// void emplace_back (Args&&... args) {}

			bool empty() const {}
		
			iterator end() {}

			const_iterator end() const {}

			iterator erase (iterator position) {}
		
			iterator erase (iterator first, iterator last) {}

			reference front() {}
		
			const_reference front() const {}

			allocator_type get_allocator() const {}

			iterator insert (iterator position, const value_type& val) {}

			void insert (iterator position, size_type n, const value_type& val) {}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) {}

			size_type max_size() const {}

			reference operator[] (size_type n) {}

			const_reference operator[] (size_type n) const {}

			void pop_back() {}

			void push_back (const value_type& val) {}

			reverse_iterator rbegin() {}

			const_reverse_iterator rbegin() const {}

			reverse_iterator rend() {}
		
			const_reverse_iterator rend() const {}

			void reserve (size_type n) {}

			void resize (size_type n, value_type val = value_type()) {}

			void shrink_to_fit() {}

			void swap (vector& x) {}

			size_type size() const {}

			protected:
				pointer				_pointer;
				size_type			_size;
				size_type			_capacity;
				allocator_type		_alloc;
	};


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
		
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}


	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {}

	}