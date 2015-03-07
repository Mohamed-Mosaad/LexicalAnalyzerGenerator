
#include <vector>
#include "NFA.h"

using namespace std;

/*
 * To call this methods : Operation::KleenClosure(a);
 */
class Operation{

public:
	static NFA* Or(NFA* a, NFA* b){

		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(a->start, epsillon));
		cur->start->next.push_back(make_pair(b->start, epsillon));

		a->accept->next.push_back(make_pair(cur->accept, epsillon));
		b->accept->next.push_back(make_pair(cur->accept, epsillon));

		a->accept->setState(NTH);
		b->accept->setState(NTH);

		return cur;

	}

	static NFA* And(NFA* a, NFA* b){

		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(a->start, epsillon));
		a->accept->next.push_back(make_pair(b->start, epsillon));
		b->accept->next.push_back(make_pair(cur->accept, epsillon));

		a->accept->setState(NTH);
		b->accept->setState(NTH);

		return cur;

	}

	static NFA* KleenClosure(NFA* a){

		NFA* cur=new NFA();

		cur->start->next.push_back(make_pair(cur->accept, epsillon));
		cur->start->next.push_back(make_pair(a->start, epsillon));
		a->accept->next.push_back(make_pair(cur->accept, epsillon));
		a->accept->next.push_back(make_pair(a->accept, epsillon));

		a->accept->setState(NTH);

		return cur;
	}

	static NFA* positiveClosure(NFA* a){

		NFA* cur=KleenClosure(a);

		a->accept->setState(NTH);

		return And(a, cur);

	}

};

