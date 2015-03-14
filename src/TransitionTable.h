/*
 * TransitionTable.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Omar-Arafa
 */
#include <map>
#include "Node.h"
#include <vector>
#include <string>
#include <queue>
#include "Dstate.h"
#ifndef TRANSITIONTABLE_H_
#define TRANSITIONTABLE_H_
using namespace std;
class Transition_Table {
public:
	Transition_Table(map<int ,Node*>index_map,vector<char> inputs,int starting_state);
	Dstate * epsilon_closure(Dstate * state);
	Dstate * move(Dstate* state ,char ch);
	void generate_table();
	virtual ~Transition_Table();
	map<int ,Node*>index_map;
	vector<vector<Dstate *> > table;
	vector<char> inputs;
	int starting_state;
	int counter;
};

#endif /* TRANSITIONTABLE_H_ */
