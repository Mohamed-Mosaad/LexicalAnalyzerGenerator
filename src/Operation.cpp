/*
 * Operation.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: user
 */

#include "Operation.h"

#include <vector>
#include "NFA.h"
#include <stack>
#include <iostream>

namespace Operation{

/*
 * To call this methods : Operation::KleenClosure(a);
 */
//class Operation{

//public:
//	static int num;
	NFA* Or(NFA* a, NFA* b){


		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(a->start, epsillon));
		cur->start->next.push_back(make_pair(b->start, epsillon));

		a->accept->next.push_back(make_pair(cur->accept, epsillon));
		b->accept->next.push_back(make_pair(cur->accept, epsillon));

		a->accept->setState(NTH);
		b->accept->setState(NTH);

//		cout<<"NFA Or\n";


		return cur;

	}

	NFA* And(NFA* a, NFA* b){

		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(a->start, epsillon));
		a->accept->next.push_back(make_pair(b->start, epsillon));
		b->accept->next.push_back(make_pair(cur->accept, epsillon));

		a->accept->setState(NTH);
		b->accept->setState(NTH);

//		cout<<"NFA And\n";

		return cur;

	}

	NFA* KleenClosure(NFA* a){

		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(cur->accept, epsillon));
		cur->start->next.push_back(make_pair(a->start, epsillon));
		a->accept->next.push_back(make_pair(cur->accept, epsillon));
		a->accept->next.push_back(make_pair(a->start, epsillon));

		a->accept->setState(NTH);

//		cout<<"NFA Kleen\n";


		return cur;
	}

	NFA* positiveClosure(NFA* a){

		NFA* cur=KleenClosure(a);

		a->accept->setState(NTH);

//		cout<<"NFA Positive\n";


		return And(a, cur);

	}

}


