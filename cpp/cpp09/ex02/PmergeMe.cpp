#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		saveToList(av[i]);
		saveToDeque(av[i]);
	}
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	*this = obj;
}

PmergeMe::~PmergeMe() {

}

PmergeMe & PmergeMe::operator=(const PmergeMe& obj) {
	if (this != &obj)
	{
		this->list = obj.getList();
		this->deque = obj.getdeque();
	}
	return *this;
}

bool PmergeMe::isValidPositiveInt(int num) {
	if (num < 0 || num > std::numeric_limits<int>::max())
		return false;
	return true;
}

void PmergeMe::print_list() {
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
}

void PmergeMe::print_deque() {
	for (int i = 0; i < (int)deque.size(); i++)
		std::cout << deque[i] << " ";
}

// void PmergeMe::start() {
// 	print_list();
// }

void PmergeMe::saveToDeque(const char* input) {
	std::istringstream iss(input);
	int num;
	while(iss >> num) {
		if (isValidPositiveInt(num)) {
			deque.push_back(num);
		}
		else 
			return ;
	}
}

void PmergeMe::saveToList(const char* input) {
	std::istringstream iss(input);
	int num;
	while(iss >> num) {
		if (isValidPositiveInt(num)) {
			list.push_back(num);
		}
		else {
			std::cout << "Invalid positive integer: " << num << std::endl;
			return;
		}
	}
}

std::list<int> PmergeMe::getList() const {
	return this->list;
}

std::deque<int> PmergeMe::getdeque() const {
	return this->deque;
}