/*
 * Dstate.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Omar-Arafa
 */
#include <vector>
#ifndef DSTATE_H_
#define DSTATE_H_

using namespace std;
class Dstate {
public:
	Dstate(int ID , vector<int> NFA_States);
	virtual ~Dstate();
	int ID;
	vector<int> NFA_States;
};

#endif /* DSTATE_H_ */
