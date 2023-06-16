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

void PmergeMe::start() {
	mergeInsertSort(this->list);
}

std::list<int> PmergeMe::insertSort(std::list<int>& list)
{
	// for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
	// {
	// 	std::list<int>::iterator j = i;
	// 	while (j != list.begin() && *(--j) > *i)
	// 	{
	// 		std::list<int>::iterator next = j;
	// 		++next;
	// 		std::swap(*next, *j);
	// 	}
	// }
	// return list;
	std::list<int>::iterator it = list.begin();
    std::list<int>::iterator end = list.end();

    for (++it; it != end; ++it) {
        int value = *it;
        std::list<int>::iterator hole = it;
        std::list<int>::iterator prevHole = hole;
        --prevHole;

        while (hole != list.begin() && value < *prevHole) {
            *hole = *prevHole;
            hole = prevHole;
            --prevHole;
        }

        *hole = value;
    }
	return list;
}

std::list<int> PmergeMe::mergeSort(const std::list<int>& left, const std::list<int>& right) {
	std::list<int> merged;
	std::list<int>::const_iterator leftIt = left.begin();
	std::list<int>::const_iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end()){
		if (*leftIt <= *rightIt){
			merged.push_back(*leftIt);
			++leftIt;
		}
		else {
			merged.push_back(*rightIt);
			++rightIt;
		}
	}
	while (leftIt != left.end()){
		merged.push_back(*leftIt);
		++leftIt;
	}
	while (rightIt != right.end())
	{
		merged.push_back(*rightIt);
		++rightIt;
	}
	return merged;
}

std::list<int> PmergeMe::mergeInsertSort(std::list<int>& list) {
	std::list<int>::iterator it = list.begin();

	if (list.size() <= 10)
		return insertSort(list);
	std::advance(it, list.size() / 2);
	std::list<int> ll(list.begin(), it);
	std::list<int> rl(it, list.end());

	ll = mergeInsertSort(ll);
	rl = mergeInsertSort(rl);
	return mergeSort(ll, rl);
}

std::list<int> PmergeMe::getList() const {
	return this->list;
}

std::deque<int> PmergeMe::getdeque() const {
	return this->deque;
}