#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>

typedef std::string t_string;

class Fixed {
	private:
		int _value;
		static const int _fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int getRawBits() const;
		void setRawBits(int const raw);

};

#endif
