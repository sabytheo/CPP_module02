#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	// Constructeur par défaut
	Fixed(void);

	// Constructeur de recopie
	Fixed(const Fixed& other);

	// Surcharge de l'opérateur d'affectation
	Fixed& operator=(const Fixed& other);

	// Destructeur
	~Fixed(void);

	// Fonctions membres
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
