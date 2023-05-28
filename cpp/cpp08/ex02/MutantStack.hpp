#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
 public:
	MutantStack() : std::stack<T>(){};
	MutantStack(const MutantStack& obj) : std::stack<T>(obj){};
	MutantStack& operator=(const MutantStack& obj) {
		std::stack<T>::operator=(obj);
		return (*this);
	}
	~MutantStack() {};

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin(void) {
		return (std::stack<T>::c.begin());
	}
	iterator end(void) {
		return (std::stack<T>::c.end());
	}
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(void) {
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend(void) {
		return (std::stack<T>::c.rend());
	}
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	const_iterator cbegin(void) const {
		return (std::stack<T>::c.cbegin());
	}
	const_iterator cend(void) const {
		return (std::stack<T>::c.cend());
	}
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin(void) const {
		return (std::stack<T>::c.crbegin());
	}
	const_reverse_iterator crend(void) const {
		return (std::stack<T>::c.crend());
	}
};

#endif