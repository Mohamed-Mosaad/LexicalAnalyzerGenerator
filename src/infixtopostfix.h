/*
 * infixtopostfix.h
 *
 *  Created on: Mar 7, 2015
 *      Author: mos3aad
 */

#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include<iostream>
#include<cstring>
#include<stack>
#include "Operation.cpp"
class infixtopostfix {
public:
	infixtopostfix();
	NFA* infixtopostfix1(string infix, int size);
	int getWeight(char ch);
	virtual ~infixtopostfix();
};

#endif /* INFIXtoPOSTFIX_H_ */
