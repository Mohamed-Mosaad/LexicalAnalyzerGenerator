/*
 * infix2postfix.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: mos3aad
 */

#include "infix2postfix.h"

infix2postfix::infix2postfix() {
	// TODO Auto-generated constructor stub

}

infix2postfix::~infix2postfix() {
	// TODO Auto-generated destructor stub
}
/*
 * InfixToPostFix.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: mos3aad
 */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include<iostream>
#include<cstring>
#include<stack>
#include <unordered_map>
using namespace std;




// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0
int getWeight(char ch) {
   switch (ch) {
      case '+': return 3;
      case '*': return 3;
      case '~': return 2;
      case '|': return 1;
      default : return 0;
   }
}

// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size) {
   stack<char> s;
   map <char, NFA> map;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   // iterate over the infix expression
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         // simply push the opening parenthesis
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         // if we see a closing parenthesis,
         // pop of all the elements and append it to
         // the postfix expression till we encounter
         // a opening parenthesis
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
         // pop off the opening parenthesis also
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // we saw an operand
         // simply append it to postfix expression
         postfix[k++] = ch;

      }
      else {
         // we saw an operator
         if (s.empty()) {
            // simply push the operator onto stack if
            // stack is empty
            s.push(ch);
            NFA operand = new NFA(ch);
            map.insert(std::pair<char,int>(ch,operand));
         }
         else {
            // pop of all the operators from the stack and
            // append it to the postfix expression till we
            // see an operator with a lower precedence that
            // the current operator
            while (!s.empty() && s.top() != '(' &&
                  weight <= getWeight(s.top())) {
               postfix[k++] = s.top();
               s.pop();

            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   // and append it to postfix expression
   while (!s.empty()) {
      postfix[k++] = s.top();
      s.pop();
   }
   postfix[k] = 0; // null terminate the postfix expression
   for(int i=size-1;i<=0;i--){
	  s.push(postfix[i]);
   }
   while(!s.empty()){

	   	  char operand1=s.pop();
	   	  char c2=s.pop();

	   	  if(c2=='*'||c2=='+'){


	   	  }else { // c2  is  an operand

	   		  	 char op_rator = s.pop();

	   	  }
   }
}

// main
int main() {
	int x=5;
	cout <<~5;
   char infix[] = "(a|b)*~c~d";
   int size = strlen(infix);
   char postfix[size];
   infix2postfix(infix,postfix,size);
   cout<<"\nInfix Expression :: "<<infix;
   cout<<"\nPostfix Expression :: "<<postfix;
   cout<<endl;
   return 0;
}

