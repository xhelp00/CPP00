#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
//#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _que;

public:
	PmergeMe();
	PmergeMe(int ac, char *av[]);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	std::vector<int> sorted(std::vector<int> &ref);
	std::deque<int> sorted(std::deque<int> &ref);
	void showSorted();
};

std::ostream &operator<<(std::ostream &os, const std::deque<int> &que);
std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec);

#endif