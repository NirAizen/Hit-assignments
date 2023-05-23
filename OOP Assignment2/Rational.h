#pragma once
#include"Polynomial.h"

class Rational
{
private:
	Polynomial _nom;
	Polynomial _denom;
public:
	Rational();
	Rational(Polynomial&, Polynomial&);
	Rational(Rational const&);
	void print()const;
	Polynomial& getNom();
	Polynomial& getDenom();
	friend ostream& operator<<(ostream&, const Rational&);
	friend Rational operator*(Rational const, Rational const&);
	friend Rational operator+(Rational const, const Rational&);
	Rational& operator=(const Rational&);
	~Rational() {};
};

