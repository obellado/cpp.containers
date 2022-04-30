#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

namespace ft {
    template<class T, class Container = std::vector<T> > // STD::vector

    class stack {

        public:
            typedef Container                           container_type;
            typedef typename Container::value_type      value_type;
            typedef typename Container::size_type       size_type;
            typedef typename Container::reference       reference;
            typedef typename Container::const_reference const_reference;

        protected:
            Container      container;

        public:

            explicit stack( const Container& cont = Container() ) : container(cont) {}

            stack( const stack& other ) : container(other.container) {}

            virtual ~stack() {}

            stack& operator=( const stack& other ) {
                container = other.container;
                return *this;
            }

            reference top() {
                return container.back();
            }
            
            const_reference top() const {
                return container.back();
            }

            bool empty() const {
                return container.empty();
            }

            size_type size() const {
                return container.size();
            }

            void push( const value_type& value ) {
                container.push_back(value);
            }

            void pop() {
                container.pop_back();
            }

            // template <class T2, class Container2>
            friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container == rhs.container; }

            // template <class T2, class Container2>
            friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container != rhs.container; }

            // template <class T2, class Container2>
            friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container < rhs.container; }

            // template <class T2, class Container2>
            friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container <= rhs.container; }

            // template <class T2, class Container2>
            friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container > rhs.container; }

            // template <class T2, class Container2>
            friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.container >= rhs.container; }
    };
}

#endif
