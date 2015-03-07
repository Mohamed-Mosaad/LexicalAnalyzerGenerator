/*
 * Node.h
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */


#ifndef NODE_H_
#define NODE_H_

#define START 0
#define NTH 1
#define ACCEPT 2

#include <vector>

const char epsillon='\L';


using namespace std;

class Node {

public:
	Node();
	virtual ~Node();
	vector< pair<Node*, char> > next;
	int getState();
	void setState(int newState);

private:
	int state;
};

#endif /* NODE_H_ */
