#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
 private:
	std::string ideas[100];
 public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	
	Brain& operator=(const Brain& obj);
};

#endif
