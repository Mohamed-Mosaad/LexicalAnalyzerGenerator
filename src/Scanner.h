/*
 * Scanner.h
 *
 *  Created on: Mar 7, 2015
 *      Author: Omar-Arafa
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
using namespace std;
#ifndef SCANNER_H_
#define SCANNER_H_

class Scanner {
public:
	Scanner(string fileName);
	string getNextToken();
	bool isOperator(char token);
	void tokenizer();
	string getLine();
	bool isEOF();
	virtual ~Scanner();
private:
	bool eof;
	string line;
	string operators ;
	int index;
	vector<string> tokens;

};

#endif /* SCANNER_H_ */
