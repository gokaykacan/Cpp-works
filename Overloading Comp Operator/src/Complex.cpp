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

Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}
Complex operator+(const Complex &c1, double d){
	return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1){
	return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex::Complex(): real(0), imaginary(0) {
	// TODO Auto-generated constructor stub

}
Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {
	//(cout << "Copy Const!" << endl;
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
bool Complex::operator==(const Complex &other) const{
	if(real == other.real && imaginary == other.imaginary)
		return true;
	else
		return false;
}
Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

