#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath>

typedef std::string t_string;

class Fixed {
	private:
		int _value;
		static const int _fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

};

#endif
