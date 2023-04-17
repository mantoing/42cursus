#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>


class DiamondTrap {
 private:
	std::string _name;
 public:
	DiamondTrap(/* args */);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& obj);
};

#endif
