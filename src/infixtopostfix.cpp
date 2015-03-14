/*
 * infixtopostfix.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: mos3aad
 */

#include "infixtopostfix.h"
using namespace std;
infixtopostfix::infixtopostfix() {
	// TODO Auto-generated constructor stub

}

infixtopostfix::~infixtopostfix() {
	// TODO Auto-generated destructor stub
}
/*
 * InfixToPostFix.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: mos3aad
 */



// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0
int infixtopostfix:: getWeight(char ch) {
	switch (ch) {
	case '+':
		return 3;
	case '*':
		return 3;
	case '~':
		return 2;
	case '|':
		return 1;
	default:
		return 0;
	}
}

// convert infix expression to postfix using a stack
NFA* infixtopostfix:: infixtopostfix1(string infix, int size) {
	stack<char> s;
	//map <char, NFA> map;
	string postfix="";
	int weight;
	int i = 0;
	int k = 0;
	char ch;
	// iterate over the infix expression
	 bool preceded_by_slash=false;
	while (i < size) {

		ch = infix[i];
		if(ch=='\\'){
			preceded_by_slash=true;
			continue;
		}
		if(preceded_by_slash){
			preceded_by_slash=false;
			postfix+= s.top();
			k++;
			continue;

		}
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
				postfix+= s.top();
				k++;
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
			postfix+= ch;
			k++;

		} else {
			// we saw an operator
			if (s.empty()) {
				// simply push the operator onto stack if
				// stack is empty
				s.push(ch);

			} else {
				// pop of all the operators from the stack and
				// append it to the postfix expression till we
				// see an operator with a lower precedence that
				// the current operator
				while (!s.empty() && s.top() != '('
						&& weight <= getWeight(s.top())) {
					postfix+= s.top();
					k++;
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
		postfix+= s.top();
		k++;
		s.pop();
	}
	//postfix[ = 0; // null terminate the postfix expression
	cout <<"Postfix :"<<postfix<<endl;

	// Added 8/3/2015 by 3M.A.N

	for (int i = postfix.size()-1; i >= 0; i--) {
		s.push(postfix[i]);
	}
	NFA* result = new NFA();// will contain the final NFA for the given expression

	char operand1 = s.top();
	s.pop();
	if (s.empty()) { // Regex consists of only 1 element
		result = new NFA(operand1);
	} else {
		char c2 = s.top();
		s.pop();

		if (c2 == '*' || c2 == '+') { // c2 is operator (unary operator)
			NFA* op1 = new NFA(operand1);
			if (c2 == '*') {
				result = Operation::KleenClosure(op1);
			} else {
				result = Operation::positiveClosure(op1);

			}
		} else { // c2  is  an operand

			char op_rator = s.top();
			s.pop();
		//	cout<<operand1<<" "<<op_rator<<" "<<c2<<endl;
			NFA* op1 = new NFA(operand1);
			NFA* op2 = new NFA(c2);
			if (op_rator == '|') {
				result = Operation::Or(op1, op2);
			} else {
				result = Operation::And(op1, op2);

			}

		}
	}

	//cout<<s.size()<<endl;
	while (!s.empty()) {
		char c=s.top();// may be uniary operator or operand waiting for its operator
		s.pop();
		if(c=='+'){
			result = Operation::positiveClosure(result);

		}else if (c=='*'){
			result = Operation::KleenClosure(result);
		}else {
			NFA* op2= new NFA(c);
			char opertor =s.top();
			s.pop();
			if(opertor=='|'){
				result = Operation::Or(result,op2);
			}else{
				result = Operation::And(result,op2);

			}
		}

	}
	return result;
}



//int main() {
//
//	string infix = "(\+)|(-)";
//
//
//	//char postfix[size];
//	//cout<< size<<endl;
//int size =infix.size();
//
//	infixtopostfix* ob1= new infixtopostfix();
//	ob1->infixtopostfix1(infix, size);
//	cout<<"herererere";
//	//cout << "\nInfix Expression :: " << infix;
//	//cout << "\nPostfix Expression :: " << postfix;
//	cout << endl;
//	return 0;
//}

