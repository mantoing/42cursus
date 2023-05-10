#include "Base.hpp"

Base *generate(void)
{
	srand(time(nullptr));
	int r;

	r = rand() % 3;
	switch (r) {
		case 0 : return (new A());
		case 1 : return (new B());
		case 2 : return (new C());
		default: return (nullptr);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p) != nullptr) {
		std::cout << "A's Pointer" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != nullptr) {
		std::cout << "B's Pointer" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != nullptr) {
		std::cout << "C's Pointer" << std::endl;
	}
	else {
		std::cout << "None of a, b, or c" << std::endl;
	}
}

static void trycatchidentify(Base &p, std::string type){
	try
	{
		if (type == "A")
			(void)dynamic_cast<A &>(p);
		if (type == "B")
			(void)dynamic_cast<B &>(p);
		if (type == "C")
			(void)dynamic_cast<C &>(p);
		std::cout << type << "'s Reference" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

void identify(Base &p)
{
	trycatchidentify(p, "A");
	trycatchidentify(p, "B");
	trycatchidentify(p, "C");
}

int main() {
	Base* b;

	b = generate();
	identify(b);
	identify(*b);
	delete b;
	return (0);
}