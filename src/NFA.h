/*
 * NFA.h
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#ifndef NFA_H_
#define NFA_H_

#include "Node.h"

using namespace std;

class NFA {
public:
	NFA();
	NFA(char c);
	virtual ~NFA();

	Node* start;
	Node* accept;

};

#endif /* NFA_H_ */
