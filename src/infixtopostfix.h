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
	string infixtopostfix1(string infix, int size);

	NFA*  postfixToNFA(string postfix);

	int getWeight(char ch);
	virtual ~infixtopostfix();


	char AND;
	//char OR;
	char KLEENE;
	char POSITIVE;

};

#endif /* INFIXtoPOSTFIX_H_ */
