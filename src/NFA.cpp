/*
 * NFA.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: user
 */

#include "NFA.h"

using namespace std;


NFA::NFA() {

	start=new Node();
	start->setState(START);
	accept = new Node();
	accept->setState(ACCEPT);
}

NFA::NFA(char c) {

	start=new Node();
	start->setState(START);
	accept = new Node();
	accept->setState(ACCEPT);

	start->next.push_back(make_pair(accept, c));
}

NFA::~NFA() {
	delete(start);
	delete(accept);
}
/*
NFA* NFA::Or(NFA* a, NFA* b){

	NFA* cur=new NFA();

	cur->start->next.push_back(make_pair(a->start, epsillon));
	cur->start->next.push_back(make_pair(b->start, epsillon));

	a->accept->next.push_back(make_pair(cur->accept, epsillon));
	b->accept->next.push_back(make_pair(cur->accept, epsillon));

	a->accept->setState(NTH);
	b->accept->setState(NTH);

	return cur;

}

NFA* NFA::And(NFA* a, NFA* b){

	NFA* cur=new NFA();

	cur->start->next.push_back(make_pair(a->start, epsillon));
	a->accept->next.push_back(make_pair(b->start, epsillon));
	b->accept->next.push_back(make_pair(cur->accept, epsillon));

	a->accept->setState(NTH);
	b->accept->setState(NTH);

	return cur;

}

NFA* NFA::KleenClosure(NFA* a){

	NFA* cur=new NFA();

	cur->start->next.push_back(make_pair(cur->accept, epsillon));
	cur->start->next.push_back(make_pair(a->start, epsillon));
	a->accept->next.push_back(make_pair(cur->accept, epsillon));
	a->accept->next.push_back(make_pair(a->accept, epsillon));

	a->accept->setState(NTH);

	return cur;
}

NFA* NFA::positiveClosure(NFA* a){

	NFA* cur=KleenClosure(a);

	a->accept->setState(NTH);

	return And(a, cur);

}
*/
