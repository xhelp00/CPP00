#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
			std::stack<int>		_stack;
	public:
			RPN();
			~RPN();
			RPN(const RPN &other);
			RPN &operator=(const RPN &other);

			int		calculate(char *str);
			void	operation(char c);
};

#endif