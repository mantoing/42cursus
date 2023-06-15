#include <iostream>
#include <list>
#include <deque>
#include <sstream> // For istringstream

// 함수: 양의 정수 시퀀스를 정수 배열로 변환하여 list에 저장
void SaveToList(const char* input, std::list<int>& myList) {
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        if (number > 0) {
            myList.push_back(number);
        }
    }
}

// 함수: 양의 정수 시퀀스를 정수 배열로 변환하여 deque에 저장
void SaveToDeque(const char* input, std::deque<int>& myDeque) {
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        if (number > 0) {
            myDeque.push_back(number);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program_name positive_integer_sequence\n";
        return 1;
    }

    const char* input = argv[1];

    // list에 저장하기
    std::list<int> myList;
    SaveToList(input, myList);

    // deque에 저장하기
    std::deque<int> myDeque;
    SaveToDeque(input, myDeque);

    // list 출력
    std::cout << "List: ";
    for (std::list<int>::const_iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // deque 출력
    std::cout << "Deque: ";
    for (std::deque<int>::const_iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}