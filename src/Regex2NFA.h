/*
 * Regex2NFA.h
 *
 *  Created on: Mar 8, 2015
 *      Author: mos3aad
 */
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
#ifndef REGEX2NFA_H_
#define REGEX2NFA_H_

class Regex2NFA {
public:
	Regex2NFA(string exp);
	virtual ~Regex2NFA();

	string expression;
};

#endif /* REGEX2NFA_H_ */
