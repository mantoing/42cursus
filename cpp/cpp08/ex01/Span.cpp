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
	if ((this->vec).capacity() == (this->vec).size())
		throw FullVecException();
	(this->vec).push_back(value);
}

unsigned int Span::shortestSpan(void){
	if ((this->vec).size() < 2)
		throw OnlyOneException();
	std::vector<int> sort_vec;
	sort_vec.reserve((this->vec).capacity());
	std::copy((this->vec).begin(), (this->vec).end(), back_inserter(sort_vec));
	std::sort(sort_vec.begin(), sort_vec.end());
	std::adjacent_difference(sort_vec.begin(), sort_vec.end(), sort_vec.begin());
	sort_vec.erase(sort_vec.begin());
	return (*min_element(sort_vec.begin(), sort_vec.end()));
}

unsigned int Span::longestSpan(void) {
	if ((this->vec).size() < 2)
		throw OnlyOneException();
	return (*max_element((this->vec).begin(), (this->vec).end()) - \
			*min_element((this->vec).begin(), (this->vec).end()));
}