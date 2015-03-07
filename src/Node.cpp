/*
 * Node.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#include "Node.h"


using namespace std;

Node::Node() {

}

Node::~Node() {

}

int Node::getState(){
	return state;
}
void Node::setState(int newState){
	state=newState;
}

