#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:

		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& copy);

		Fixed& operator=(const Fixed& other);

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();


		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);


		static const Fixed& min(const Fixed& value1, const Fixed& value2);
		Fixed& min(Fixed& value1, Fixed& value2);
		static const Fixed& max(const Fixed& value1, const Fixed& value2);
		Fixed& max(Fixed& value1, Fixed& value2);

		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os,const Fixed& other);

#endif
