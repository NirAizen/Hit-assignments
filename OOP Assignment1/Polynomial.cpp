#include "Polynomial.h"

int Polynomial::_maxDeg = 0;

Polynomial::Polynomial() :_degree(0), _lastDeg(0), _arrSize(1) {
	this->createArr(1);
	this->setCoeff(0, 0);
}

Polynomial::Polynomial(int deg) :_degree(deg), _lastDeg(0), _arrSize(deg) {
	this->createArr(this->_degree);
}

Polynomial::Polynomial(double* arr, int deg) : _degree(deg), _arrSize(deg+1) {
	this->_arr = new double[deg+1];
	for (int i = 0; i < deg+1; i++)
		this->_arr[i] = arr[i];
	setLastDeg();
	if (this->_lastDeg > this->_maxDeg)
		this->_maxDeg = this->_lastDeg;
}

Polynomial::Polynomial(const Polynomial& other) {   // copy constructor
	this->_degree = other._degree;
	this->_lastDeg = other._lastDeg;
	this->_arrSize = other._arrSize;
	this->_arr = new double[_degree + 1];
	for (int i = 0; i < _arrSize; i++)
		this->_arr[i] = other._arr[i];
}
Polynomial::~Polynomial() {
	delete[] this->_arr;
};
void Polynomial::setLastDeg() {
	for (int i = 0; i < this->_arrSize; i++) {
		if (this->_arr[i])
			this->_lastDeg = i;
	}
}
int Polynomial::getDegree(bool what) const {
	if (!what) return this->_degree;
	else return this->_lastDeg;
}
int Polynomial::getMaxDegree() {
	return _maxDeg;
}
void Polynomial::print() {
	if (!isEmpty()) cout << "polynomial = 0";
	else {
		this->setLastDeg();
		cout << "polynomial = " << this->_arr[0];
		for (int i = 1; i <= this->_lastDeg; i++) {
			cout << "+" << this->_arr[i] << "X^" << i;
		}
	}
	cout << endl;
}

void Polynomial::createArr(const int deg) {
	this->_arr = new double[deg];
	for (int i = 0; i < this->_arrSize; i++)
		this->_arr[i] = 0;
}

void Polynomial::setCoeff(const int index, const double num) {
	this->_arr[index] = num;
	if (index > this->_maxDeg) { this->_maxDeg = index; }
}

bool Polynomial::isEmpty() const {
	for (int i = 0; i < this->_arrSize; i++)
	{
		if (this->_arr[i] != 0)
			return true;
	}
	return false;
}

double Polynomial::getCoeff(int deg) const {
	double val = 0;
	if (deg >= 0 && deg <= this->_arrSize) // taking care of array overflow and underflow by setting the value to 0.
		val = this->_arr[deg];
	return val;
}
