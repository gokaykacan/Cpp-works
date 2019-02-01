/*
 * Complex.h
 *
 *  Created on: 9 Kas 2018
 *      Author: 26005010
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include<iostream>
using namespace std;

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	Complex &operator=(const Complex &other);
	double getReal() const {
		return real;
	}
	double getImaginary() const {
		return imaginary;
	}
	void setReal(double real2){
		real = real2;
	}
	void setImaginary(double imaginary2){
		imaginary = imaginary2;
	}
	virtual ~Complex();
};

ostream &operator<<(ostream &out, const Complex &other);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

#endif /* COMPLEX_H_ */
