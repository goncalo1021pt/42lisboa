#ifndef iter_HPP
# define iter_HPP

# include <iostream>
# include <string>

template<typename T1, typename T2, typename T3>
void iter(T1 addr, T2 len, T3 func) {
	for (T2 i = 0; i < len; i++) {
		func(addr[i]);
	}
}

template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}
#endif
