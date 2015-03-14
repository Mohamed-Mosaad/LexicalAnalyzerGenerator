/*
 * Scanner.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Omar-Arafa
 */

#include "Scanner.h"
using namespace std;
Scanner::Scanner(string fileName) {
	freopen(fileName.c_str(), "r", stdin);
	operators = "+*():=|-[]{}";
	eof = false;
	index = 0;
}
void Scanner::tokenizer() {
	if (!getline(cin, line)) {
		eof = true;
	} else {
		tokens.clear();
		index = 0;
		int begin = 0;
		for (int i = 0; i < (int) line.length(); i++) {
			if ((!(i > 0 && isOperator(line[i]) && line[i - 1] == '\\'))
					&& (isOperator(line[i]) || line[i] == ' ')) {
				if (begin < i) {
					string tmp = line.substr(begin, i - begin);
					tokens.push_back(tmp);
				}
				if (line[i] != ' ') {
					string tmp = line.substr(i, 1);
					tokens.push_back(tmp);
				}
				begin = i + 1;
			}
		}
		string tmp = line.substr(begin, line.length() - begin);
		tokens.push_back(tmp);
	}
}
bool Scanner::isEOF() {
	return eof;
}
string Scanner::getNextToken() {
	if (index == (int) tokens.size())
		return "\0";
	return tokens[index++];
}
string Scanner::getLine() {
	string myLine;
	getline(cin, line);
	for (int i = 0; i < (int) line.length(); i++) {
		if (line[i] != ' ')
			myLine += line[i];
	}
	return myLine;
}
bool Scanner::isOperator(char token) {
	for (int i = 0; i < (int) operators.length(); i++) {
		if (operators[i] == token)
			return true;
	}
	return false;
}

Scanner::~Scanner() {
}

