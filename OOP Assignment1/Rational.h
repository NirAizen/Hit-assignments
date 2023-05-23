#pragma once
#include "Polynomial.h"

class Rational
{
private:
	Polynomial* _nom;
	Polynomial* _denom;
public:
	Rational();
	Rational(Polynomial&, Polynomial&);
	Rational(const Rational& other);
	~Rational();
	Polynomial& getNom() const;
	Polynomial& getDenom() const;
	void print();
};

