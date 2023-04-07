#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>


class FragTrap: public ClapTrap{
 public:
	FragTrap();
	FragTrap(std::string _name);
	~FragTrap();
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap& frag);
	void highFivesGuys(void);
};

#endif