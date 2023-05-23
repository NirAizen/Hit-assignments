#include "Rational.h"

Rational::Rational() {
	this->_nom = new Polynomial();
	this->_denom = new Polynomial();
	this->_denom->setCoeff(0, 1);
}

Rational::Rational(const Rational& other) :_nom(other._nom), _denom(other._denom) {} // copy constructor

Rational::Rational(Polynomial& nom, Polynomial& denom) {
	this->_nom = &nom;
	if(!denom.isEmpty())
		this->_denom->setCoeff(0, 1);
	this->_denom = &denom;
}

Polynomial& Rational::getNom() const {
	return *(this->_nom);
}
Polynomial& Rational::getDenom() const {
	return *(this->_denom);
}

Rational::~Rational() {}

void Rational::print() {
	this->_nom->print();
	cout << "--------------------------" << endl;
	this->_denom->print();
}