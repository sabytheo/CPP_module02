#include "../include/Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructeur de recopie
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Surcharge de l'opérateur d'affectation
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
	}
	return *this;
}

// Destructeur
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Fonction membre getRawBits
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

// Fonction membre setRawBits
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
