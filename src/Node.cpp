/*
 * Node.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#include "Node.h"
#include "Operation.cpp"

using namespace std;
int num=0;

Node::Node() {
	id=num;
	num++;

	Operation::nodeMap[id]=this;
}

Node::~Node() {

}

int Node::getState(){
	return state;
}
void Node::setState(int newState){
	state=newState;
}


string Node::getType(){
	return type;
}
void Node::setType(string newType){
	type=newType;
}
