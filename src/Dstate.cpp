/*
 * Dstate.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Omar-Arafa
 */

#include "Dstate.h"

Dstate::Dstate(int ID , vector<int> NFA_States) {
	this->ID = ID;
	this->NFA_States = NFA_States;
}

Dstate::~Dstate() {
	// TODO Auto-generated destructor stub
}

