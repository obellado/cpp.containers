#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

	template< class Iter >
	struct iterator_traits {
        typedef typename Iter::iterator_category iterator_category;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
    };

    template< class T >
    struct iterator_traits<T*> {
        typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
    };

    template< class T >
    struct iterator_traits<const T*> {
        typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
    };

    struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	// struct iterator {
	// 	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	// 	typedef typename ft::iterator_traits<Iter>::value_type value_type;
	// 	typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
	// 	typedef typename ft::iterator_traits<Iter>::pointer pointer;
	// 	typedef typename ft::iterator_traits<Iter>::reference reference;
	// };

    template<class Iter>
	class Shmiterator {

		public:

			typedef Iter iterator_type;
			typedef Shmiterator<Iter> myIterator;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type Distance;
			typedef typename ft::iterator_traits<iterator_type>::pointer Pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference Reference;

		protected:

			Pointer current;

		public:

			Shmiterator() {}
			explicit Shmiterator(Pointer P) : current(P) {}
			Shmiterator(const Shmiterator<Iter> &X) : current(X.base()) {}

			Pointer base() const {
				return current;
			}
			Reference operator*() const {
				return *current;
			}
			Pointer operator->() const {
				return &**this;
			}

			myIterator &operator++() {
				++current;
				return *this;
			}
			myIterator &operator--() {
				--current;
				return *this;
			}
			myIterator operator++(int) {
				myIterator tmp = *this;
				++current;
				return tmp;
			}
			myIterator operator--(int) {
				myIterator tmp = *this;
				--current;
				return tmp;
			}

			myIterator &operator+=(Distance N) {
				current += N;
				return *this;
			}
			myIterator &operator-=(Distance N) {
				current -= N;
				return *this;
			}
			myIterator operator+(Distance N) const {
				return (myIterator(current + N));
			}
			myIterator operator-(Distance N) const {
				return (myIterator(current - N));
			}

			bool operator==(int Y) const {
				return current == (Pointer)Y;
			}
			bool operator==(const myIterator &Y) const {
				return current == Y.current;
			}
			bool operator!=(const myIterator &Y) const {
				return !(*this == Y);
			}

			Reference operator[](Distance N) const {
				return *(*this + N);
			}

			bool operator<(const myIterator &Y) const {
				return current < Y.current;
			}
			bool operator>(const myIterator &Y) const {
				return Y < *this;
			}
			bool operator<=(const myIterator &Y) const {
				return !(Y < *this);
			}
			bool operator>=(const myIterator &Y) const {
				return !(*this < Y);
			}

			Distance operator-(const myIterator &Y) const {
				return (current - Y.current);
			}

	};

	template<class T> inline
	Shmiterator<T> operator+(typename Shmiterator<T>::Distance N, const Shmiterator<T> &Y) {
		return (Y + N);
	}

    template<class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator iterator_type;

			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type Distance;
			typedef typename ft::iterator_traits<iterator_type>::pointer Pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference Reference;
		protected:
		Iterator current;

		public:
		// data types

		typedef reverse_iterator<Iterator> myIterator;

		// constructors
		reverse_iterator() {}
		explicit reverse_iterator(iterator_type X) : current(X) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &X) : current(X.base()) {}

		// member fuctions
		iterator_type base() const {
			return current;
		}
		Reference operator*() const {
			Iterator tmp = current;
			return *--tmp;
		}
		Pointer operator->() const {
			return &**this;
		}

		myIterator &operator++() {
			--current;
			return *this;
		}
		myIterator &operator--() {
			++current;
			return *this;
		}
		myIterator operator++(int) {
			myIterator tmp = *this;
			--current;
			return tmp;
		}
		myIterator operator--(int) {
			myIterator tmp = *this;
			++current;
			return tmp;
		}

		myIterator &operator+=(Distance N) {
			current -= N;
			return *this;
		}
		myIterator &operator-=(Distance N) {
			current += N;
			return *this;
		}
		myIterator operator+(Distance N) const {
			return myIterator(current - N);
		}
		myIterator operator-(Distance N) const {
			return myIterator(current + N);
		}

		Reference operator[](Distance N) const {
			return *(*this + N);
		}

		bool Eq(const myIterator &Y) const {
			return current == Y.current;
		}
		bool Lt(const myIterator &Y) const {
			return current < Y.current;
		}

	};

	template<class Iterator> inline
	bool operator==(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return X.Eq(Y);
	}
	template<class Iterator> inline
	bool operator!=(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return !(X == Y);
	}

	template<class Iterator> inline
	bool operator<(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return X.Lt(Y);
	}
	template<class Iterator> inline
	bool operator>(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return Y < X;
	}

	template<class Iterator> inline
	bool operator<=(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return !(Y < X);
	}
	template<class Iterator> inline
	bool operator>=(const reverse_iterator<Iterator> &X, const reverse_iterator<Iterator> &Y) {
		return !(X < Y);
	}

}

#endif