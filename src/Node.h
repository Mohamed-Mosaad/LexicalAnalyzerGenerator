/*
 * Node.h
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */


#ifndef NODE_H_
#define NODE_H_

#include <vector>

using namespace std;

class Node {

public:
	Node();
	virtual ~Node();

	vector< pair<Node*, char> > next;

};

#endif /* NODE_H_ */
