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
		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;
		bool operator>(const Fixed &copy) const;
		bool operator<(const Fixed &copy) const;
		bool operator>=(const Fixed &copy) const;
		bool operator<=(const Fixed &copy) const;
		bool operator==(const Fixed &copy) const;
		bool operator!=(const Fixed &copy) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		static Fixed &min(Fixed &x, Fixed &y);
		static const Fixed &min(const Fixed &x, const Fixed &y);
		static Fixed &max(Fixed &x, Fixed &y);
		static const Fixed &max(const Fixed &x, const Fixed &y);

};

#endif
