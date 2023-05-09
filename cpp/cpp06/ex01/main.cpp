#include "Serialization.hpp"

int main(int ac, char *av[])
{
	Data prev;
	Data *next;
	uintptr_t ptr;

	if (ac != 2)
	{
		std::cout << "argument count is not 2" << std::endl;
		return (1);
	}	
	prev.name = av[1];
	std::cout << "prev : " << prev.name << std::endl;

	ptr = Serialization::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serialization::deserialize(ptr);
	std::cout << "next : " << next->name << std::endl;

	return (0);
}