#pragma once
#include<iostream>
using namespace std;

class Polynomial
{
private:
	static int _maxDeg;
	int _deg;
	double* _arr;
public:
	Polynomial();
	Polynomial(int const);
	Polynomial(const Polynomial&);
	Polynomial(double* const, int const);
	void print()const;
	double getCoeff(int const index)const;
	void setCoeff(int, double);
	int getDegree(bool)const;
	static int getMaxDegree();
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend Polynomial operator+(Polynomial& , const Polynomial);
	Polynomial& operator=(const Polynomial&);
	friend Polynomial operator*(const double&, const Polynomial&);
	friend Polynomial operator*(const Polynomial, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	double operator[](const int&);
	const double operator[](const int&)const;
	~Polynomial();
};
