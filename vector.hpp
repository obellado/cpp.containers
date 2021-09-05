#include <iostream>
// #include <compare>
// #include <initializer_list>

namespace ft {
template < class T, class Alloc = std::allocator<T> > class vector {
	
	public:

		using value_type             = T;
		using allocator_type         = Allocator;
		using pointer                = typename allocator_traits<Allocator>::pointer;
		using const_pointer          = typename allocator_traits<Allocator>::const_pointer;
    	using reference              = value_type&;
    	using const_reference        = const value_type&;
    	using size_type              = /* implementation-defined */;
    	using difference_type        = /* implementation-defined */;
    	using iterator               = /* implementation-defined */;
    	using const_iterator         = /* implementation-defined */;
    	using reverse_iterator       = std::reverse_iterator<iterator>;
    	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		explicit vector (const allocator_type& alloc = allocator_type()) {}

		explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) {}

		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) {}

		vector (const vector& x) {}

		~vector() {}
		
	private:
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

		vector& operator= (const vector& x) {}

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