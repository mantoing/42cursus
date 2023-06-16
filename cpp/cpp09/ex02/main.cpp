#include "PmergeMe.hpp"

// 1. 명령줄에서 양의 정수 시퀀스를 입력 받음
// 2. 입력된 시퀀스를 파싱하여 정수 배열로 변환
// 3. 정렬되기 전의 양의 정수 시퀀스 출력

// 4. 첫 번째 컨테이너를 사용하여 병합-삽입 정렬 알고리즘 수행
//    - 정렬 시작 시간 기록
//    - 병합-삽입 정렬 알고리즘 수행
//    - 정렬된 양의 정수 시퀀스 출력
//    - 첫 번째 컨테이너를 사용하여 정렬에 소요된 시간 계산 및 출력

// 5. 두 번째 컨테이너를 사용하여 병합-삽입 정렬 알고리즘 수행
//    - 정렬 시작 시간 기록
//    - 병합-삽입 정렬 알고리즘 수행
//    - 정렬된 양의 정수 시퀀스 출력
//    - 두 번째 컨테이너를 사용하여 정렬에 소요된 시간 계산 및 출력
// ㅏ 
// 6. 프로그램 종료

bool isValidvalue(const std::string& arg) {
	if (arg.empty() || arg[0] == '-')
		return false;
	for (std::size_t i = 0; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i]))
			return false;
	}
   return true;
}

int main(int ac, char **av){
	if (ac < 2) {
		std::cout << "Error: ac error" << std::endl;
		return 1;
	}
   PmergeMe myPmerge(ac, av);
   for (int i = 1; i < ac; ++i) {
      if (isValidvalue(av[i]) == false){
         std::cout << "Error: ac something wrong" << std::endl;
         return 1;
      }
   }
   std::cout << "LIST before :" << std::endl;
   myPmerge.print_list();
   myPmerge.start();
   std::cout << "List after :" << std::endl;
   myPmerge.print_list();

   // std::cout << "DEQUE" << std::endl;
   // myPmerge.print_deque();
   return 0;
}