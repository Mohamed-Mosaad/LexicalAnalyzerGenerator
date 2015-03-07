/*
 * NFA.h
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#ifndef NFA_H_
#define NFA_H_

#include "Node.h"
#include <vector>

using namespace std;

class NFA {
public:
	NFA();
	virtual ~NFA();

	vector<Node*> node;

	NFA Or(NFA a, NFA b);

	Node* start;
	Node* accept;

};

#endif /* NFA_H_ */
