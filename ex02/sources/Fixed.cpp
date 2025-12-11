#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (other.getRawBits() > this->getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return !(this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return !(this->getRawBits() < other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return !(this->getRawBits() == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed tmp;
	tmp._rawBits = this->getRawBits() + other.getRawBits();
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed tmp;
	tmp._rawBits = this->getRawBits() - other.getRawBits();
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	++this->_rawBits;
	return *this;
}

Fixed &Fixed::operator--()
{
	--this->_rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return((Fixed&)value2);
	else
		return((Fixed&)value1);
}

Fixed& Fixed::min(Fixed& value1, Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return(value2);
	else
		return(value1);
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return((Fixed&)value1);
	else
		return((Fixed&)value2);
}
Fixed& Fixed::max(Fixed& value1, Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return(value1);
	else
		return(value2);
}


float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawBits) / static_cast<float>((1 << this->_fractionalBits)));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}
