#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <limits>
# include <list>
# include <deque>

class PmergeMe {
 private:
	std::list<int> list;
	std::deque<int> deque;
	bool isValidPositiveInt(int num);
	void saveToList(const char* input);
	void saveToDeque(const char* input);
 public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);
	// void start();

	void print_deque();
	void print_list();
	std::list<int> getList() const;
	std::deque<int> getdeque() const;
};

#endif
