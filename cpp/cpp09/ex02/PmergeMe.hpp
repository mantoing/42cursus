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
	std::list<int> insertSort(std::list<int>& list);
	std::list<int> mergeSort(const std::list<int>& left, const std::list<int>& right);
	std::list<int> mergeInsertSort(std::list<int>& list);
 public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);
	void start();

	void print_deque();
	void print_list();
	std::list<int> getList() const;
	std::deque<int> getdeque() const;
};

#endif
