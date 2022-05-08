#include <iostream>
#include <sys/time.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

// #include <map>
// #include <stack>
// #include <vector>

// #include <stdlib.h>
// #include "stack.hpp"

struct timeval tv_start;
struct timeval tv_stop;
struct timeval tv_diff;

#if false
# define NS "-------- std --------"
# include <vector>
# include <stack>
// # include <iterator>
// # include <utility>
// # include <map>
// # include <set>
namespace ft = std;
#else
# define NS "--------- ft --------"
# include "vector.hpp"
# include "stack.hpp"
// # include "iterators/iterator.hpp"
// # include "iterators/iterator_traits.hpp"
// # include "iterators/reverse_iterator.hpp"
// # include "iterators/Ptrit.hpp"
// # include "utils/utility.hpp"
// # include "tree/map.hpp"
// # include "tree/set.hpp"
#endif

void startTimer() {
    gettimeofday(&tv_start, NULL);
}

void stopTimer() {
    gettimeofday(&tv_stop, NULL);
}

void printTimerDiff() {
    tv_diff.tv_sec = tv_stop.tv_sec - tv_start.tv_sec;
    tv_diff.tv_usec = tv_stop.tv_usec - tv_start.tv_usec;
    printf("mcs\t= %li\n", tv_diff.tv_sec * 1000000 + tv_diff.tv_usec);
    printf("ms\t= %li\n", tv_diff.tv_sec * 1000 + tv_diff.tv_usec / 1000);
    printf("s\t= %li\n", tv_diff.tv_sec + tv_diff.tv_usec / 1000000);
}

void stackTest() {
    std::cout << YELLOW << "###### stack ######" << RESET  << std::endl;
    startTimer();
    /* stack */
    ft::stack<int> stack;
    std::cout << "stack:\t\tdefault" << std::endl;

    bool empty = stack.empty();
    std::cout << "empty:\t\t" << std::boolalpha << empty << std::endl;

    ft::stack<int>::size_type size = stack.size();
    std::cout << "size:\t\t" << size << std::endl;

    const ft::stack<int>::value_type &to_push = 5;
    stack.push(to_push);
    std::cout << "push:\t\t" << to_push << std::endl;

    empty = stack.empty();
    std::cout << "empty:\t\t" << std::boolalpha << empty << std::endl;

    size = stack.size();
    std::cout << "size:\t\t" << size << std::endl;

    if (empty == false) {
        ft::stack<int>::value_type &top = stack.top();
        std::cout << "top:\t\t" << top << std::endl;

        stack.pop();
        std::cout << "pop:\t\t" << to_push << std::endl;
    }

    ft::stack<int> copy_stack;
    std::cout << "stack:\t\tfor copy" << std::endl;

    copy_stack.push(to_push);
    std::cout << "push:\t\t" << to_push << std::endl;

    const ft::stack<int> const_stack = copy_stack;
    std::cout << "stack:\t\tconst" << std::endl;

    const ft::stack<int>::value_type &const_top = const_stack.top();
    std::cout << "const top:\t" << const_top << std::endl;

    ft::stack<int> stack1;
    std::cout << "stack1:\t\tcompare" << std::endl;

    ft::stack<int> stack2;
    std::cout << "stack2:\t\tcompare" << std::endl;

    bool compare = stack1 == stack2;
    std::cout << "==:\t\t" << std::boolalpha << compare << std::endl;

    compare = stack1 != stack2;
    std::cout << "!=:\t\t" << std::boolalpha << compare << std::endl;

    compare = stack1 < stack2;
    std::cout << "<:\t\t" << std::boolalpha << compare << std::endl;

    compare = stack1 > stack2;
    std::cout << ">:\t\t" << std::boolalpha << compare << std::endl;

    compare = stack1 <= stack2;
    std::cout << "<=:\t\t" << std::boolalpha << compare << std::endl;

    compare = stack1 >= stack2;
    std::cout << ">=:\t\t" << std::boolalpha << compare << std::endl;
    /* stack */
    stopTimer();
    std::cout << RED << "---------------------" << std::endl;
    std::cout << "#### stack timer ####" << std::endl;
    printTimerDiff();
    std::cout << "---------------------" << RESET << std::endl;
}

void    vectorTest() {
    
    std::cout << RED << "###### vector ######" << std::endl;
    startTimer();
    ft::vector<int> vectorDefault;
    std::cout << "vector:\t\t\t\tdefault" << std::endl;

    ft::vector<std::string> vector(5, "hi");

    std::cout << "vector of strings:\t\t" << vector[4] << std::endl;
 
    vector.push_back("bye");
    vector.push_back("bye");
    vector.push_back("bye");
    vector.push_back("bye");
    vector.push_back("bye");
    vector.push_back("bye");
    std::cout << "vector after push_back:\t\t" << vector[10] << std::endl;

    std::cout << "vector1's max_size():\t\t" << vector.max_size() << std::endl;
    std::cout << "vector1's size:\t\t\t" << vector.size() << std::endl;
    std::cout << "vector1's capacity:\t\t" << vector.capacity() << std::endl;

    std::string aloha = "aloha";
    vector.assign(3, aloha);
    std::cout << "vector after assign :\t\t" << vector[1] << std::endl;
    

    stopTimer();
    std::cout << GREEN << "----------------------" << std::endl;
    std::cout << "#### vector timer ####" << std::endl;
    printTimerDiff();
    std::cout << "----------------------" << RESET << std::endl;
}

int main() {
    std::cout << GREEN << NS << RESET << std::endl;

    // stackTest();
    vectorTest();

	return 0;
}