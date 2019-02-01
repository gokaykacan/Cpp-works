/*
 * Complex.cpp
 *
 *  Created on: 9 Kas 2018
 *      Author: 26005010
 */

#include "Complex.h"

ostream &operator<<(ostream &out, const Complex &other){
	out << "(" << other.getReal() << ", " << other.getImaginary() << ")" ;
	return out;
}

Complex::Complex(): real(0), imaginary(0) {
	// TODO Auto-generated constructor stub

}
Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {
	cout << "Copy Const!" << endl;
}
Complex::Complex(const Complex &other){
	real = other.real;
	imaginary=other.imaginary;
}

Complex &Complex::operator=(const Complex &other){
	real = other.real;
	imaginary = other.imaginary;
	cout << "Assignment Overloading !" << endl;
	return *this;
}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

