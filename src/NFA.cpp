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

NFA* NFA::Or(NFA* a, NFA* b){

	NFA* cur=new NFA();

	cur->start->next.push_back(make_pair(a->start, '\L'));
	cur->start->next.push_back(make_pair(b->start, '\L'));

	a->accept->next.push_back(make_pair(cur->accept, '\L'));
	b->accept->next.push_back(make_pair(cur->accept, '\L'));

	return cur;

}

NFA* NFA::And(NFA* a, NFA* b){

	NFA* cur=new NFA();

	cur->start->next.push_back(make_pair(a->start, '\L'));
	cur->start->next.push_back(make_pair(b->start, '\L'));

	a->accept->next.push_back(make_pair(cur->accept, '\L'));
	b->accept->next.push_back(make_pair(cur->accept, '\L'));

	return cur;

}

