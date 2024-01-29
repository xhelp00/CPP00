#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &other)
{
	*this = other; 
}

RPN& RPN::operator=(const RPN &other)
{
	this->_stack = other._stack;
	return *this;
}

void RPN::operation(char c)
{
	if (c == ' ')
		return ;
	int num1;
	int num2;
	if (_stack.size() > 1)
	{
		num2 = _stack.top();
		_stack.pop();
		num1 = _stack.top();
		_stack.pop();
		if (c == '+')
			_stack.push(num1 + num2);
		else if (c == '-')
			_stack.push(num1 - num2);
		else if (c == '*')
			_stack.push(num1 * num2);
		else if (c == '/')
		{
			if (num2 == 0)
				throw "Error: divide by 0";
			_stack.push(num1 / num2);
		}
		else
			throw "Error: unknown operator";
	}
	else
		throw "Error: too few numbers for calculation";
}

int	RPN::calculate(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else
			operation(str[i]);
		i++;
	}
	if (_stack.size() == 1)
		return _stack.top();
	else
		throw "Error: there are numbers left in the stack";
}
