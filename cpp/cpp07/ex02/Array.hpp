#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
 private:
	unsigned int _size;
	T *_data;
	
 public:
	Array() : _size(0), _data(NULL) {};
	Array(unsigned int n) : _size(n), _data(new T(n)) {};
	Array(const Array& obj) : _size(obj._size), _data(new T[obj._size]) {
		for (unsigned int i = 0; i < _size; i++) {
			_data[i] = obj._data[i];
		}
	};
	~Array() {
		delete [] _data;
	};
	Array& operator=(const Array& obj) {
		if (this != obj){
			T *tmp = new T[obj._size];
			for (unsigned int i = 0; i < obj._size; i++){
				tmp[i] = obj._data[i];
			}
			delete [] _data;
			_size = obj._size;
			_data = obj._data;
		}
		return (*this);
	};
	class OutOfBound : public std::exception {
			public:
					const char *what() const throw() {
						return ("**** Out of Bound! ****");
					}

	};
	T& operator[](unsigned int i) {
		if (i >= _size) {
			throw(OutOfBound());
		}
		return (_data[i]);
	}
	unsigned int size() const {
		return (_size);
	}
};

#endif
