/*
 * NFA.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#include "NFA.h"
#include <vector>

using namespace std;

NFA::NFA() {

	start=new Node();
	accept = new Node();
}

NFA::~NFA() {
	// TODO Auto-generated destructor stub
}

