/*
 * Simulator.h
 *
 *  Created on: Mar 14, 2015
 *      Author: mos3aad
 */

#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include<iostream>
#include<cstring>
#include<stack>
#include "Dstate.h"
#include <map>
#include "Node.h"
#include <vector>
#include <string>
#include <queue>
#include "Dstate.h"
using namespace std;

class Simulator {
public:

	Simulator(string fileName,vector<char>);
		string getNextToken();
		bool isOperator(char token);
		void tokenizer();
		string getLine();
		bool isEOF();

		void simulate(vector< vector<Dstate *> > DFA_table,string token);

private:
		bool eof;
		string line;
		string operators ;
		int index;
		vector<string> tokens;
		vector<vector<Dstate *> > table;

	virtual ~Simulator();
};

#endif /* SIMULATOR_H_ */
