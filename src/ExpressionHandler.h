/*
 * ExpressionHandler.h
 *
 *  Created on: Mar 12, 2015
 *      Author: Omar-Arafa
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <map>
#include "Scanner.h"
using namespace std;

#ifndef EXPRESSIONHANDLER_H_
#define EXPRESSIONHANDLER_H_

class ExpressionHandler {
public:
	ExpressionHandler(string fileName);
	void interpreter();
	vector<string> keyword(vector<string> tokens);
	vector<string> punctuation(vector<string> tokens);
	vector<string> expression(vector<string> tokens);
	vector<string> definition(vector<string> tokens);
	map <string,vector<string> > getMap();
	bool isOp(char ch);
	bool canOp(char ch);
	vector<string> addCat(vector<string> tokens);
	string filter(string src);
	vector<string> getExpressions();
	virtual ~ExpressionHandler();
private:
	Scanner *scan;
	string specialOperators ;
	string validOp ;
	string catChar;
	map <string,vector<string> > mapExp;
	vector<string> expressions;
};

#endif /* EXPRESSIONHANDLER_H_ */
