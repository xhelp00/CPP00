#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int ac, char *av[])
{
	for (int i = 0; i < ac; i++)
	{
		const std::string arg = av[i];
		int tmp = std::atoi(av[i]);
		if (tmp == 0 && arg.find_first_not_of("0") != std::string::npos)
		{
			throw std::runtime_error("non numeric entry");
		}
		if (tmp < 0)
			throw std::runtime_error("negative value given");
		_vec.push_back(tmp);
		_que.push_back(tmp);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe(void)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_que = other._que;
	}
	return *this;
}

std::vector<int> PmergeMe::sorted(std::vector<int> &ref)
{
	std::vector<int> a;
	std::vector<int> b;

	for (std::vector<int>::iterator it = ref.begin(); it != ref.end(); it++)
	{
		b.push_back(*(it++));
		if (it == ref.end())
		{
			a.push_back(-1);
			break;
		}
		else
			a.push_back(*it);
	}

	for (std::size_t i = 0; i < b.size(); i++)
	{
		if (a[i] > b[i])
		{
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}

	for (std::size_t i = 1; i < b.size(); i++)
	{
		std::size_t tmp = i;
		std::size_t temp2 = i - 1;
		while (tmp != 0 && b[tmp] < b[temp2])
		{
			std::swap(b[tmp], b[temp2]);
			std::swap(a[tmp], a[temp2]);
			--tmp;
			--temp2;
		}
	}

	std::vector<int> sorted(b);

	if (a[0] != -1)
		sorted.insert(sorted.begin(), a[0]);
	for (std::size_t i = 1; i < a.size(); i++)
	{
		if (a[i] == -1)
			continue;
		std::vector<int>::iterator it = std::find(sorted.begin(), sorted.end(), b[i]);
		while (it != sorted.begin() && a[i] < *(it - 1))
			it--;
		sorted.insert(it, a[i]);
	}
	return sorted;
}

std::deque<int> PmergeMe::sorted(std::deque<int> &ref)
{
	std::deque<int> a;
	std::deque<int> b;

	for (std::deque<int>::iterator it = ref.begin(); it != ref.end(); it++)
	{
		b.push_back(*it);
		it++;
		if (it == ref.end())
		{
			a.push_back(-1);
			break;
		}
		else
			a.push_back(*it);
	}

	for (std::size_t i = 0; i < b.size(); i++)
	{
		if (a[i] > b[i])
		{
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}

	for (std::size_t i = 1; i < b.size(); i++)
	{
		std::size_t tmp = i;
		std::size_t temp2 = i - 1;
		while (tmp != 0 && b[tmp] < b[temp2])
		{
			std::swap(b[tmp], b[temp2]);
			std::swap(a[tmp], a[temp2]);
			--tmp;
			--temp2;
		}
	}

	std::deque<int> sorted(b);
	if (a[0] != -1)
		sorted.insert(sorted.begin(), a[0]);
	for (std::size_t i = 1; i < a.size(); i++)
	{
		if (a[i] == -1)
			continue;
		std::deque<int>::iterator it = std::find(sorted.begin(), sorted.end(), b[i]);
		while (it != sorted.begin() && a[i] < *(it - 1))
			it--;
		sorted.insert(it, a[i]);
	}

	return sorted;
}

void PmergeMe::showSorted()
{
	clock_t start, stop;

	std::cout << "Before:" << _vec << std::endl;
	start = clock();
	std::vector<int> tmpvec = sorted(_vec);
	stop = clock();
	std::cout << "After:" << tmpvec << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : ";
	std::cout << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;

	std::cout << "Before:" << _que << std::endl;
	start = clock();
	std::deque<int> tmpdq = sorted(_que);
	stop = clock();
	std::cout << "After:" << tmpdq << std::endl;
	std::cout << "Time to process a range of " << _que.size() << " elements with std::deque  : ";
	std::cout << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::deque<int> &que)
{
	for (std::deque<int>::const_iterator it = que.begin(); it != que.end(); it++)
	{
		int tmp = *it;
		os << " " << tmp;
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		int tmp = *it;
		os << " " << tmp;
	}
	return os;
}