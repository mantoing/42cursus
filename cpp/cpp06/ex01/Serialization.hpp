#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

struct Data {
	std::string name;
};


class Serialization {
 public:
	Serialization();
	Serialization(const Serialization& obj);
	~Serialization();
	Serialization& operator=(const Serialization& obj);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
