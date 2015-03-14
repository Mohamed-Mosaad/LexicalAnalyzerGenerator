/*
 * Operation.h
 *
 *  Created on: Mar 14, 2015
 *      Author: user
 */
//
#ifndef OPERATION_H_
#define OPERATION_H_

#include "NFA.h"
#include <map>

namespace Operation {
	static NFA* Or(NFA* a, NFA* b);
	static NFA* And(NFA* a, NFA* b);
	static NFA* KleenClosure(NFA* a);
	static NFA* positiveClosure(NFA* a);

	static map<int, Node*> nodeMap;
	static vector<char> CharVector;
}

#endif /* OPERATION_H_ */
