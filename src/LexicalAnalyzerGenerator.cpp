//============================================================================
// Name        : LexicalAnalyzerGenerator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Scanner.h"
#include "ExpressionHandler.h"
#include "infixtopostfix.h"
#include "Simulator.h"

using namespace std;
int main(){
	cout<<"MAIN"<<endl;
Simulator* ob= new Simulator("input.txt");
ob->tokenizer();
}
//int main() {
//	//cout << "!!!^_________________^Hnhgjkjello World!!!^__^" << endl; // prints !!!Hello World!!!
//	int x = 1232312;
//	//cout  << 3*x << endl;
//	infixtopostfix* ob1=new infixtopostfix();
//	ExpressionHandler * e = new ExpressionHandler("format.txt");
//	map <string,vector<string> > mymap = e->getMap();
//	map <string,vector<string> >::iterator it;
//	vector<string> all;
//	for(it = mymap.begin();it!=mymap.end();it++){
//		//cout <<"23456456";
//		//cout<<it->first<<endl;
//		vector<string> temp = it->second;
//		string exp = "";
//		//cout<<temp.size()<<endl;
//
//		for(int i =0;i<temp.size();i++){
//			for(int j = 0; j< temp[i].length();j++)
//				exp+=temp[i][j];
//		}
//		cout<<exp<<" "<<endl;
//
//		all.push_back(exp);
//
//		//cout<<endl;
//	}
//	for(int i = 0;i<2;i++){
//		NFA* r = ob1->infixtopostfix1(all[i],all[i].size());
//	}
//	//cout <<"54564545";
//	//Scanner *s = new Scanner("format.txt");
//	//string line;
//	//vector<string> tokens;
////	while(!s->isEOF()){
////		s->tokenizer();
////		while((line = s->getNextToken())!="\0"){
////			tokens.push_back(line);
////		}
////		for(int i = 0; i<(int)tokens.size();i++)
////			cout<<tokens[i]<<endl;
////		tokens.clear();
////	}
//	return 0;
//}
