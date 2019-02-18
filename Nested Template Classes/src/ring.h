/*
 * ring.h
 *
 *  Created on: 4 Þub 2019
 *      Author: 26005010
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template <class T>
class ring {
public:
	class iterator;

};

template<class T>
class ring<T>::iterator{
public:
	void print(){
		cout << "Hello from iterator" << T() << endl;
	}
};



#endif /* RING_H_ */
