#include "MutantStack.hpp"

#include <cstdlib>		// For rand() and srand()
#include <ctime>		// For time()

template <typename T>
void printStack(std::stack<T> myStack) {
	while (!myStack.empty()) {
		std::cout << myStack.top() << " ";
		myStack.pop();
	}
	std::cout << std::endl;
}

int	main(void)
{
	{ //subject test
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{ //additional test
		MutantStack<char> mstack;
		mstack.push('a');
		mstack.push('m');
		mstack.push('a');
		mstack.push('z');
		mstack.push('i');
		mstack.push('n');
		mstack.push('g');
		mstack.push('!');
		mstack.push(' ');
		mstack.push('i');
		mstack.push('t');
		mstack.push(' ');
		mstack.push('w');
		mstack.push('o');
		mstack.push('r');
		mstack.push('k');
		mstack.push('s');
		mstack.push(' ');
		mstack.push('l');
		mstack.push('i');
		mstack.push('k');
		mstack.push('e');
		mstack.push(' ');
		mstack.push('a');
		mstack.push(' ');
		mstack.push('m');
		mstack.push('a');
		mstack.push('g');
		mstack.push('i');
		mstack.push('c');
		mstack.push('!');
		std::cout << "Iterating the mutant stack now" << std::endl;
		MutantStack<char>::iterator it;
		for (it = mstack.begin(); it != mstack.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

	}
	return 0;
}