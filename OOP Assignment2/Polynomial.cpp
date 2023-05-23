#include<iostream>
#include "Polynomial.h"
using namespace std;

int Polynomial::_maxDeg = 0;
Polynomial::Polynomial()
{
	this->_deg = 0;
	this->_arr = new double[1];
	this->_arr[0] = 0;
}
Polynomial::Polynomial(const Polynomial& poly) {
	if (!this->_arr)
		delete[] this->_arr;
	int deg = poly.getDegree(true);
	this->_deg = poly._deg;
	int x = this->_deg + 1;
	this->_arr = new double[x];
	for (int i = 0; i < x; i++) {
		this->_arr[i] = poly._arr[i];
	}
	if (deg > _maxDeg)
		_maxDeg = deg;
}
Polynomial::Polynomial(int const Degree) {
	this->_deg = Degree;
	this->_arr = new double[Degree + 1];
	for (int i = 0; i <= Degree; i++)
		this->_arr[i] = 0;
}
Polynomial::Polynomial(double* const coef, int const Degree) {
	int i, largest = 0;

	this->_deg = Degree;
	this->_arr = new double[Degree + 1];
	for (int i = 0; i <= Degree; i++)
		this->_arr[i] = 0;
	for (i = 0; i <= this->_deg; i++) {
		this->_arr[i] = coef[i];
	}
	largest = getDegree(true);
	if (largest > this->_maxDeg)
		this->_maxDeg = largest;
}
double Polynomial::getCoeff(int const index)const {
	if (index<0 || index>this->_deg)
		return -1234.56;
	else
		return _arr[index];
}
int Polynomial::getDegree(bool what)const {
	int count = 0;
	if (what)
	{
		for (int i = 0; i <= this->_deg; i++)
			if (this->_arr[i] != 0)
				count = i;
		return count;
	}
	else
		return this->_deg;
}
void Polynomial::print()const {
	int i, index = getDegree(true);
	cout << "Polynomial=" << this->_arr[0];
	for (i = 1; i <= index; i++) {
		cout << "+(" << this->_arr[i] << ")*X^" << i;
	}
	cout << endl;
}
void Polynomial::setCoeff(int power, double coef) {
	this->_arr[power] = coef;
	if (power > this->_maxDeg && coef != 0)
		this->_maxDeg = power;
}
int Polynomial::getMaxDegree() {
	return _maxDeg;
}
Polynomial& Polynomial:: operator=(const Polynomial& other) {
	delete[]this->_arr;
	this->_deg = other._deg;
	this->_arr = new double[_deg + 1];
	for (int i = 0; i <= _deg; i++)
		this->_arr[i] = other._arr[i];
	return *this;
}
double Polynomial::operator[](const int& index) {
	double num = 0;
	if (index<0 || index>this->_deg)
		num = -1234.56;
	else
		num = this->getCoeff(index);
	return num;
}
const double Polynomial:: operator[](const int& index)const {
	double num = 0;
	if (index<0 || index>this->_deg)
		num = -1234.56;
	else
		num = this->getCoeff(index);
	return num;
}
ostream& operator<<(ostream& out, const Polynomial& p1) {
	p1.print();
	return out;
}
Polynomial operator+(Polynomial& other, const Polynomial other2) {
	int i, deg1 = other.getDegree(true), deg2 = other2.getDegree(true);
	if (deg2 < deg1)
	{
		Polynomial p1(other);
		for (i = 0; i <= deg2; i++)
			p1._arr[i] += other2.getCoeff(i);
		return p1;
	}
	else
	{
		Polynomial p1(other2);
		for (i = 0; i <= deg1; i++)
			p1._arr[i] += other.getCoeff(i);
		return p1;
	}
}
Polynomial operator*(const double& num, const Polynomial& other) {
	Polynomial p1(other);
	int i;
	for (i = 0; i <= other.getDegree(true); i++)
		p1._arr[i] *= num;
	return p1;
}
Polynomial operator-(const Polynomial& other, const Polynomial& other2) {
	int i, deg1 = other.getDegree(true), deg2 = other2.getDegree(true);

	if (deg2 <= deg1) {
		Polynomial p1(other);
		for (i = 0; i <= deg2; i++)
			p1._arr[i] -= other2.getCoeff(i);
		return p1;
	}
	else {
		Polynomial p1(other2);
		for (i = 0; i <= deg1; i++)
			p1._arr[i] -= other.getCoeff(i);
		return p1;
	}
}
Polynomial operator*(const Polynomial other2, const Polynomial& other) {
	int deg1 = other.getDegree(true), deg2 = other2.getDegree(true);
	Polynomial p1(deg1 + deg2);
	int i, j = 0;
	for (i = 0; i <= deg1; i++)
		for (int j = 0; j <= deg2; j++)
			p1._arr[i + j] += other._arr[i] * other2._arr[j];
	if (p1.getDegree(true) > p1.getMaxDegree())
		p1._maxDeg = p1.getDegree(true);
	return p1;
}

Polynomial::~Polynomial() {
	delete[] this->_arr;
}