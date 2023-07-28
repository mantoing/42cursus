#include "Span.hpp"

const char* Span::FullVecException::what() const throw() {
	return ("Vec already Full");
}

const char* Span::OnlyOneException::what() const throw() {
	return ("Only one data or no data");
}

Span::Span() : vec(0, 0) {
	(this->vec).reserve(0);
}

Span::Span(unsigned int N) : vec(0, 0) {
	(this->vec).reserve(N);
}

Span::Span(const Span &obj){
	*this = obj;
}

Span::~Span(){

}

Span& Span::operator=(const Span& obj) {
	if (this != &obj)
	{
		this->N = obj.N;
		(this->vec) = obj.vec;
	}
	return (*this);
}

void Span::addNumber(int value) {
	if ((this->vec).capacity() == (this->vec).size()) //수용량과 크기를 비교해서 만약 같다면 가득차있다고 반환.
		throw FullVecException();
	(this->vec).push_back(value);
}

unsigned int Span::shortestSpan(void){
	if ((this->vec).size() < 2)
		throw OnlyOneException();
	std::vector<int> sort_vec;
	sort_vec.reserve((this->vec).capacity()); //정렬한 벡터를 저장할 공간 생성
	sort_vec = vec;
	//std::copy((this->vec).begin(), (this->vec).end(), back_inserter(sort_vec)); //sort_vec을 벡터에 추가한뒤에 처음부터 끝까지의 정렬벡터공간을 복사
	std::sort(sort_vec.begin(), sort_vec.end());
	std::adjacent_difference(sort_vec.begin(), sort_vec.end(), sort_vec.begin()); //numeric 헤더에 정의되어있는 각 요소간 인접한 차이를 계산하여 새로운 컨테이너에 저장하는 기능을 한다.
	sort_vec.erase(sort_vec.begin()); //위 adjacent_difference 를 하게 된다면 첫번째 인접한 차이를 계산한 결과가 sort_vec의 첫번째 요소에 저장이 되기 때문에 쓸데없다 따라서 지워준다.
	return (*min_element(sort_vec.begin(), sort_vec.end()));
}

unsigned int Span::longestSpan(void) {
	if ((this->vec).size() < 2)
		throw OnlyOneException();
	return (*max_element((this->vec).begin(), (this->vec).end()) - \
			*min_element((this->vec).begin(), (this->vec).end()));
}