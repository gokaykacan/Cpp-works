//============================================================================
// Name        : CharShiftTime.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include "string.h"
using namespace std;

//this function returns how many times str1 is rotated to right at str2
int CharShiftTime(char* str1, char* str2){
	int n=-1;
	unsigned int size1 = strlen(str1);
	unsigned int size2 = strlen(str2);
	int flag = 0;

	cout << "size1: " << size1 << ", size2: " << size2 << endl;
	if(size1 != size2){
		return n;
	}

	for(unsigned int i=1; i<size1; i++){
		if(str1[0] == str2[i]){
			for(unsigned int j=0; j<size2; j++){
				if((i+j) < size1){
					if(str1[j] == str2[j+i])
						flag = 1;
					else
						flag =0;
				}
				else{
					if(str1[j] == str2[(j+i)-size1])
						flag = 1;
					else
						flag = 0;
				}
			}
			if(flag){
				n = i;
				break;
			}
		}
	}

	return n;
}
int main() {

	char str1[] = "coffee";
	char str2[] = "eecoff";

	cout << "Sonuç: " << CharShiftTime(str1, str2) << endl;
	return 0;
}
