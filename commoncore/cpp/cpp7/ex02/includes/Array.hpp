#ifndef Array_HPP
# define Array_HPP

# include <iostream>
# include <exception>

template <typename T>

class Array {
	private:
		T *_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		unsigned int size() const;

		class IndexOutOfBoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		}; 
};

# include "Array.tpp"
#endif
