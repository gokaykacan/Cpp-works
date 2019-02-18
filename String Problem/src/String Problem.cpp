//============================================================================
// Name        : String.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*Senaryo:
Elimizde ard arda tekrarlayan harflerin çok sýk karþýlaþýldýðý, sadece harfler ve boþluklardan oluþan stringler var.
Bu alfabetik stringlerin içinde arka arkaya n kere veya daha fazla tekrarlayan harflerin
yýldýz karakteriyle (‘*’) deðiþtirilmiþ halini istiyoruz.

Örnek:
String verimiz “abbcccaaeeeeb bfffffca ccab” þeklinde olsun. Programýnýz çalýþtýðýnda…
n = 9 verildiðinde “abbcccaaeeeeb bfffffca ccab”
n = 5 verildiðinde “abbcccaaeeeeb b*****ca ccab”
n = 4 verildiðinde “abbcccaa****b b*****ca ccab”
n = 3 verildiðinde “abb***aa****b b*****ca ccab”
n = 2 verildiðinde “a***********b b*****ca **ab”
…sonuçlarýný vermesi beklenmektedir.

Soru: Yukarýda anlatýlan özellikleri gerçekleyen bir program yazýnýz.
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> myReturnVector (string & kelime, unsigned int n){
	unsigned int m=0;
	unsigned int l =0;
	unsigned int value = 0;
	vector<char> myV;

	//assign string to a char vector for operation
	for(unsigned int i=0; i<kelime.size(); i++){
		myV.push_back(kelime[i]);
	}

	if(myV.size()<n){
		return myV;
	}
	// count same adjacent chars, if equal to given n, keep first and last element number
	for(unsigned int j=0; j<myV.size()-1; j++){
		if(myV[j] == myV[j+1]){
			m=m+1;
			//cout <<"m: " << m << endl;
			if(m == 1){
				value = j;
			}
			if(m >= n-1){
				//cout << "l: " << l << endl;
				l = j+1;
			}
		}
		else{
			//cout << "DEBUG" << endl;
			//assign '*' character to these adjacent values
			if(value != 0 && m>=n-1){
				//cout << "value: " << value << endl;
				for(unsigned int k= value; k<=l; k++){
					myV[k] = '*';
				}
			}
			// set variables to zero new string block compare
			l = 0;
			m = 0;
			value = 0;
		}

	}

	return myV;
}
int main() {
	string kelime = "abbcccaaeeeeb bfffffca ccab";

	vector<char> myV = myReturnVector(kelime, 2);
	for(unsigned p=0; p<myV.size(); p++){
		cout << myV[p];
	}

	return 0;
}
