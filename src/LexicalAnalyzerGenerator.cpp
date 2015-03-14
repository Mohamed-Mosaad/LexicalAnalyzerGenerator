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
#include <sstream>

using namespace std;

string get_expression(vector<string> exp) {
	string conc = "";
	for (int i = 0; i < (int) exp.size(); i++) {
		for (int j = 0; j < (int) exp[i].size(); j++) {
			conc += exp[i][j];
		}
	}
	return conc;
}

int main() {

	ExpressionHandler* parser = new ExpressionHandler("format.txt");
	map<string, vector<string> > inputMap = parser->getMap();
	vector<string> expressionNames = parser->getExpressions();
	map<string, NFA*> expressionNFA;

	for (int i = 0; i < (int) expressionNames.size(); i++) {
		string concatenated_expression = get_expression(
				inputMap[expressionNames[i]]);
		infixtopostfix * converter = new infixtopostfix();
		cout<<expressionNames[i]<<" :"<<concatenated_expression<<endl;
		string postfix = converter->infixtopostfix1(concatenated_expression,concatenated_expression.size());
		cout<<postfix<<endl;
		expressionNFA[expressionNames[i]] = converter->postfixToNFA(postfix);
	}
	return 0;
}
//int main() {
//      //cout << "!!!^_________________^Hnhgjkjello World!!!^__^" << endl; // prints !!!Hello World!!!
//      int x = 1232312;
//      //cout  << 3*x << endl;
//      infixtopostfix* ob1=new infixtopostfix();
//      ExpressionHandler * e = new ExpressionHandler("format.txt");
//      map <string,vector<string> > mymap = e->getMap();
//      map <string,vector<string> >::iterator it;
//      vector<string> all;
//      for(it = mymap.begin();it!=mymap.end();it++){
//              //cout <<"23456456";
//              //cout<<it->first<<endl;
//              vector<string> temp = it->second;
//              string exp = "";
//              //cout<<temp.size()<<endl;
//
//              for(int i =0;i<temp.size();i++){
//                      for(int j = 0; j< temp[i].length();j++)
//                              exp+=temp[i][j];
//              }
//           //   cout<<exp<<" "<<endl;
//
//              all.push_back(exp);
//
//              //cout<<endl;
//      }
//      cout <<"infix "<<all[8]<<endl;
//      string ee = ob1->infixtopostfix1(all[8],all[8].size());
//      for(int i=0;i<ee.length();i++){
//
//    	  if(ee[i]==5){
//
//    		  cout<<"AND";
//    	  }else if(ee[i]==6){
//    		  cout<<"OR";
//
//
//    	  }else if(ee[i]==7){
//    		  cout<<"KLEENE";
//
//    	  }else if(ee[i]==8){
//    		  cout<<"POSITIVE";
//
//    	  }else {
//    		  cout<<ee[i];
//    	  }
//
//      } cout<<endl;
//                  //  cout<<"postfix "<<ee<<endl;
//             NFA * r = ob1->postfixToNFA(ee);
//     // cout<<all[8]<<"9"<<endl;
////      for(int i = 0;i<all.size();i++){
////          if(i==8)
////        	  continue;
////    	  string ee = ob1->infixtopostfix1(all[i],all[i].size());
////              cout<<ee<<"here"<<endl;
////            NFA * r = ob1->postfixToNFA(ee);
////      }
//      //cout <<"54564545";
//      //Scanner *s = new Scanner("format.txt");
//      //string line;
//      //vector<string> tokens;
////    while(!s->isEOF()){
////            s->tokenizer();
////            while((line = s->getNextToken())!="\0"){
////                    tokens.push_back(line);
////            }
////            for(int i = 0; i<(int)tokens.size();i++)
////                    cout<<tokens[i]<<endl;
////            tokens.clear();
////    }
//      return 0;
//}
