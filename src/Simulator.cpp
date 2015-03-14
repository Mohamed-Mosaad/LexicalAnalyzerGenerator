/*
 * Simulator.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: mos3aad
 */

#include "Simulator.h"

Simulator::Simulator(string fileName,vector <char>) {
	freopen(fileName.c_str(), "r", stdin);

	eof = false;
	index = 0;
}

void Simulator::tokenizer() {
	cout <<"TOK"<<endl;

	while (getline(cin, line)) {

		//cout <<"inTOK"<<endl;
		tokens.clear();
		index = 0;
		int begin = 0;
		string token="";
		for (int i = 0; i < (int) line.length(); i++) {
			char current=line[i];
			if(current==' '||current=='\t'){
				if(token.length()!=0){
					tokens.push_back(token);
					//cout<<token<<endl;
					token="";
				}
			}else {
					token+=current;

			}
		}
		if(token.length()!=0){
			tokens.push_back(token);

		}
		//cout<<token<<endl;
//		string tmp = line.substr(begin, line.length() - begin);
//		tokens.push_back(tmp);
	}
}

void Simulator:: simulate(vector<vector<Dstate *> > DFA_table,string token){
	Node* start =DFA_table[0][0];



}
Simulator::~Simulator() {
	// TODO Auto-generated destructor stub
}

