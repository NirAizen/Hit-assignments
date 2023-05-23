#include "Rational.h"

Rational::Rational() :_nom(0), _denom(1) {}

Rational::Rational(Polynomial& p1, Polynomial& p2) : _nom(p1), _denom(p2) {}

Rational::Rational(Rational const& other) {
	this->_nom = other._nom;
	this->_denom = other._denom;
}
void Rational::print()const {
	this->_nom.print();
	cout << "--------------------------" << endl;
	this->_denom.print();
}
Polynomial& Rational::getNom() {
	return this->_nom;
}
Polynomial& Rational::getDenom() {
	return this->_denom;
}
ostream& operator<<(ostream& out, const Rational& r1) {
	out << "numerator="; r1._nom.print();
	out << "--------------------------" << endl;
	out << "denominator="; r1._denom.print();
	return out;
}

Rational& Rational::operator=(const Rational& other) {
	this->_denom = other._denom;
	this->_nom = other._nom;
	return *this;
}

Rational operator*(Rational const other2, Rational const& other) {
	Polynomial p1(((other)._nom) * ((other2)._nom));
	Polynomial p2(((other)._denom) * ((other2)._denom));
	Rational r1(p1, p2);
	return r1;
}

Rational operator+(Rational const other, const Rational& other2) {
	Polynomial numerator1((other._nom) * (other2._denom));
	Polynomial numerator2((other2._nom) * (other._denom));
	Polynomial denomiratorshare((other._denom) * (other2._denom));
	Polynomial numshare(numerator1 + numerator2);
	Rational r1(numshare, denomiratorshare);
	return r1;
}


