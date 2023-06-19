#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <limits>
# include <list>
# include <ctime>
# include <deque>

class PmergeMe {
 private:
	std::list<int> list;
	std::deque<int> deque;
	bool isValidPositiveInt(int num);
	bool isValidvalue(const std::string& arg);
	void saveToList(const char* input);
	void saveToDeque(const char* input);
	void insertSort(std::list<int>& list);
	void mergeSort(std::list<int>& left, std::list<int>& right, std::list<int>& merged);
	void mergeInsertSort(std::list<int>& list);
	void insertSort(std::deque<int>& deque);
	void mergeSort(std::deque<int>& left, std::deque<int>& ritght, std::deque<int>& merged);
	void mergeInsertSort(std::deque<int>& deque);
 public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	void start(int ac);

	void print_deque();
	void print_list();
	void print_list(std::list<int>& tmplist);
	
	std::list<int> getList() const;
	std::deque<int> getdeque() const;
};

#endif
