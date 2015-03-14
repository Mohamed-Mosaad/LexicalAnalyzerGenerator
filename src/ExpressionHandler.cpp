/*
 * ExpressionHandler.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: Omar-Arafa
 */

#include "ExpressionHandler.h"
using namespace std;

ExpressionHandler::ExpressionHandler(string fileName) {
	scan = new Scanner(fileName);
	specialOperators = "|(";
	validOp = "|-+*)";
	catChar = "&";
	interpreter();
}
void ExpressionHandler::interpreter() {
	while (!scan->isEOF()) {
		scan->tokenizer();
		if (!scan->isEOF()) {
			string token = "";
			vector<string> tokens;
			while ((token = scan->getNextToken()) != "\0") {
				tokens.push_back(token);
			}
			if (tokens[0] == "{") {
				string key = "keyword";
				vector<string> new_tokens = keyword(tokens);
				if (mapExp.count(key) > 0) {
					vector<string> mapped = mapExp[key];
					mapped.push_back("|");
					for (int i = 0; i < (int) new_tokens.size(); i++)
						mapped.push_back(new_tokens[i]);
					mapExp[key] = mapped;
				} else {
					expressions.push_back(key);
					mapExp[key] = new_tokens;
				}
			} else if (tokens[0] == "[") {
				string key = "punctuation";
				vector<string> new_tokens = punctuation(tokens);
				if (mapExp.count(key) > 0) {
					vector<string> mapped = mapExp[key];
					mapped.push_back("|");
					for (int i = 0; i < (int) new_tokens.size(); i++)
						mapped.push_back(new_tokens[i]);
					mapExp[key] = mapped;
				} else {
					expressions.push_back(key);
					mapExp[key] = new_tokens;
				}
			} else if(tokens[1] == "="){
				string key = tokens[0];
				vector<string> new_tokens = definition(tokens);
				mapExp[key] = new_tokens;
			}else{
				string key = tokens[0];
				vector<string> new_tokens = expression(tokens);
				mapExp[key] = new_tokens;
				expressions.push_back(tokens[0]);
			}
		}
	}
}
vector<string> ExpressionHandler::keyword(vector<string> tokens) {
	vector<string> new_tokens;
	for (int i = 1; i < (int) (tokens.size() - 1); i++) {
		if (i != 1) {
			new_tokens.push_back("|");
		}
		new_tokens.push_back("(");
		for (int j = 0; j < (int) tokens[i].length(); j++) {
			string temp = "";
			temp += tokens[i][j];
			new_tokens.push_back(temp);
			if (j == (int) (tokens[i].length() - 1)) {
				new_tokens.push_back(")");
			} else {
				new_tokens.push_back(catChar);
			}
		}
	}
	return new_tokens;
}
map<string, vector<string> > ExpressionHandler::getMap() {
	return mapExp;
}
vector<string> ExpressionHandler::punctuation(vector<string> tokens) {
	vector<string> new_tokens;
	for (int i = 1; i < (int) (tokens.size() - 1); i++) {
		if (i != 1) {
			new_tokens.push_back("|");
		}
		new_tokens.push_back(tokens[i]);
//		new_tokens.push_back("(");
//		string my_token = tokens[i];
//		for (int j = 0; j < (int) my_token.length(); j++) {
//			string temp = "";
//			temp += my_token[j];
//			new_tokens.push_back(temp);
//			if (j == (int) (tokens[i].length() - 1)) {
//			//	new_tokens.push_back(")");
//			} else {
//				//new_tokens.push_back(catChar);
//			}
//		}
	}
	return new_tokens;
}
vector<string> ExpressionHandler::definition(vector<string> tokens) {
	vector<string> new_tokens;
	for(int i =2;i<(int)tokens.size();i++){
		if(tokens[i] == "-"){
			char begin = tokens[i-1][0] ;
			char end = tokens[i+1][0];
			new_tokens.pop_back();
			new_tokens.push_back("(");
			for(int j =0;(int)(begin+j)<=(int)(end);j++){
				string temp = "";
				temp += (char)(begin+j);
				new_tokens.push_back(temp);
				if((begin+j)!=end){
					new_tokens.push_back("|");
				}
			}
			new_tokens.push_back(")");
			i++;
		}else if(mapExp.count(tokens[i])>0){
			new_tokens.push_back("(");
			vector<string> tmp = mapExp[tokens[i]];
			for(int j = 0;j<(int)tmp.size();j++){
				new_tokens.push_back(tmp[j]);
			}
			new_tokens.push_back(")");
		}
		else{
			new_tokens.push_back(tokens[i]);
		}
	}
	new_tokens = addCat(new_tokens);
	return new_tokens;
}
vector<string>ExpressionHandler:: addCat(vector<string> tokens){
	vector<string> new_tokens;
	for(int i = 0;i <(int)tokens.size();i++){
		if((tokens[i].length())>1 ||(!canOp(tokens[i][0]))){
			if(i>0 && ((tokens[i-1].length() >1)||(!isOp(tokens[i-1][0])))){
				new_tokens.push_back(catChar);
			}

		}
		if(tokens[i].size()>1){
			string tmp = filter(tokens[i]);
			new_tokens.push_back("(");
			for(int i = 0; i<(int)tmp.length();i++){
				string temp = "";
				temp += tmp[i];
				int forward = 0;
				if(tmp[i] == '\\'){
					temp+=tmp[i+1];
					forward++;
				}
				if(i!=0)
					new_tokens.push_back(catChar);
				i+=forward;
				new_tokens.push_back(temp);
			}
			new_tokens.push_back(")");
		}else{
			new_tokens.push_back(tokens[i]);
		}

	}
	return new_tokens;
}
vector<string>ExpressionHandler:: expression(vector<string> tokens){
	vector<string> new_tokens = definition(tokens);
	return new_tokens;
}
string ExpressionHandler:: filter(string src){
	string dest = "";
	for(int i = 0; i< (int)(src.length()-1);i++)
		if(src[i]!='\\'||(src[i+1] == 'L' || src[i+1] == '(' || src[i+1] == ')'|| src[i+1] == '+'))
			dest += src[i];
	dest+= src[(int)(src.length()-1)];
	return dest;
}
bool ExpressionHandler::isOp(char ch){
	for(int i = 0;i<(int)specialOperators.length();i++){
		if(ch == specialOperators[i])
			return true;
	}
	return false;
}
bool ExpressionHandler::canOp(char ch){
	for(int i = 0;i<(int)validOp.length();i++){
		if(ch == validOp[i])
			return true;
	}
	return false;
}
vector<string> ExpressionHandler::getExpressions(){
	return expressions;
}
ExpressionHandler::~ExpressionHandler() {
	delete (scan);
}

