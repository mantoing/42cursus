#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		if (isValidvalue(av[i]) == false){
			std::cout << "Error: ac something wrong" << std::endl;
    		exit(1);
		}
		else {
			saveToList(av[i]);
			saveToDeque(av[i]);
		}
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

bool PmergeMe::isValidvalue(const std::string& arg) {
	if (arg.empty() || arg[0] == '-')
		return false;
	for (std::size_t i = 0; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i]))
			return false;
	}
	std::istringstream iss(arg);
	int num;
	if (!(iss >> num))
		return false;
	if (num < 0 || num > std::numeric_limits<int>::max())
		return false;
   return true;
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
	std::cout << std::endl;
}

void PmergeMe::print_list(std::list<int>& tmplist) {
	std::list<int>::iterator it;
    int count = 0;
    const int maxDisplay = 4;

    for (it = tmplist.begin(); it != tmplist.end(); it++) {
        if (count < maxDisplay) {
            std::cout << *it << " ";
            count++;
        } else {
            break;
        }
    }

    if (tmplist.size() > maxDisplay) {
        std::cout << "[...]";
    }

    std::cout << std::endl;
}

void PmergeMe::print_deque() {
	for (int i = 0; i < (int)deque.size(); i++)
		std::cout << deque[i] << " ";
}

void PmergeMe::saveToDeque(const char* input) {
	std::istringstream iss(input);
	int num;
	while(iss >> num) {
			deque.push_back(num);
	}
}

void PmergeMe::saveToList(const char* input) {
	std::istringstream iss(input);
	int num;
	while(iss >> num) {
			list.push_back(num);
	}
}

void PmergeMe::start(int ac) {
	clock_t start, end;
	std::list<int> tmplist(list);
	std::cout << "Before:  ";
	print_list(tmplist);
	mergeInsertSort(tmplist);
	std::cout << "After:  ";
	print_list(tmplist);

	start = clock();
	mergeInsertSort(list);
	end = clock();

	std::cout << "Time to process a range of  " << ac - 1 << " elements with std::list : " << end - start << " ms" << std::endl;

	start = clock();
	mergeInsertSort(deque);
	end = clock();

	std::cout << "Time to process a range of  " << ac - 1 << " elements with std::deque : " << end - start << " ms" << std::endl;

}
void PmergeMe::insertSort(std::deque<int>& deque) {
    std::deque<int>::iterator it = deque.begin();
    std::deque<int>::iterator end = deque.end();

    for (++it; it != end; ++it) {
        int value = *it;
        std::deque<int>::iterator hole = it;
        std::deque<int>::iterator prevHole = hole;
        --prevHole;

        while (hole != deque.begin() && value < *prevHole) {
            *hole = *prevHole;
            hole = prevHole;
            --prevHole;
        }

        *hole = value;
    }
}

void PmergeMe::mergeSort(std::deque<int>& left, std::deque<int>& right, std::deque<int>& merged) {
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            merged.push_back(left.front());
            left.pop_front();
        } else {
            merged.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) {
        merged.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        merged.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeInsertSort(std::deque<int>& deque) {
    if (deque.size() <= 10) {
        insertSort(deque);
        return;
    }

    std::deque<int> left, right;
    std::deque<int>::iterator it = deque.begin();
    unsigned int mid = deque.size() / 2;

    for (unsigned int i = 0; i < mid; ++i) {
        left.push_back(*it);
        ++it;
    }
    for (unsigned int j = mid; j < deque.size(); ++j) {
        right.push_back(*it);
        ++it;
    }

    mergeInsertSort(left);
    mergeInsertSort(right);

    deque.clear();
    mergeSort(left, right, deque);
}

void PmergeMe::insertSort(std::list<int>& list)
{
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
}

void PmergeMe::mergeSort(std::list<int>& left, std::list<int>& right, std::list<int>& merged) {
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			merged.push_back(left.front());
			left.pop_front();
		}
		else {
			merged.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty()) {
		merged.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty()) {
		merged.push_back(right.front());
		right.pop_front();
	}
}

void PmergeMe::mergeInsertSort(std::list<int>& list) {
	if (list.size() <= 10) {
		insertSort(list);
		return ;
	}
	std::list<int> left, right;
	std::list<int>::iterator it = list.begin();
	unsigned int mid = list.size() / 2;

	for (unsigned int i = 0; i < mid; ++i) {
		left.push_back(*it);
		++it;
	}
	for (unsigned int j = mid; j < list.size(); ++j) {
		right.push_back(*it);
		++it;
	}
	
	mergeInsertSort(left);
	mergeInsertSort(right);
	list.clear();
	mergeSort(left, right, list);
}
std::list<int> PmergeMe::getList() const {
	return this->list;
}

std::deque<int> PmergeMe::getdeque() const {
	return this->deque;
}