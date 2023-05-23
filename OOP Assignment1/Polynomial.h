#pragma once
#include <iostream>
#include <iomanip>
#include "math.h"
#include <string>

using namespace std;

class Polynomial
{
private:
	int _arrSize;
	int _degree;
	int _lastDeg;
	static int _maxDeg;
	double* _arr;
public:
	Polynomial();
	Polynomial(int);
	Polynomial(double*, int);
	Polynomial(const Polynomial&);
	~Polynomial();
	int getDegree(bool) const;
	static int getMaxDegree();
	void print();
	void setCoeff(const int, const double);
	void setLastDeg();
	void createArr(const int);
	bool isEmpty() const;
	double getCoeff(int) const;
};

