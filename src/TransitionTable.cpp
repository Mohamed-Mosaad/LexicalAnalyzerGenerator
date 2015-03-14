/*
 * TransitionTable.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Omar-Arafa
 */

#include "TransitionTable.h"

Transition_Table::Transition_Table(map<int, Node*> index_map,
		vector<char> inputs, int starting_state) {
	this->index_map = index_map;
	this->inputs = inputs;
	this->starting_state = starting_state;
	counter = 1;
}
Dstate * Transition_Table::epsilon_closure(Dstate * state) {
	vector<int> v;

	map<int, int> visited;
	for (int i = 0; i < (int) state->NFA_States.size(); i++) {
		queue<int> q;
		q.push(state->NFA_States[i]);
		while (!q.empty()) {
			int ele = q.back();
			visited[ele] = 1;
			v.push_back(ele);
			q.pop();
			Node * node = index_map[ele];
			for (int j = 0; j < node->next.size(); j++) {
				if (node->next[j].second == epsillon) {
					if (!(visited.count(node->next[j].first->id) > 0)) {
						q.push(node->next[j].first->id);
						visited[node->next[j].first->id] = 1;
					}
				}
			}
		}
	}
	Dstate * result = new Dstate(counter++, v);
	return result;
}
Dstate * Transition_Table::move(Dstate* state, char ch) {
	vector<int> v;
	map<int, int> visited;
	for (int i = 0; i < (int) state->NFA_States.size(); i++) {

		Node * node = index_map[state->NFA_States[i]];
		for (int j = 0; j < node->next.size(); j++) {
			if (node->next[j].second == ch) {
				if (!(visited.count(node->next[j].first->id) > 0)) {
					v.push_back(node->next[j].first->id);
					visited[node->next[j].first->id] = 1;
				}
			}
		}

	}
	Dstate * result = new Dstate(counter++, v);
	return result;
}
void Transition_Table::generate_table(){
	vector<int> vec;
	vector <int> dummy;
	Dstate* dummy_state = new Dstate(0,dummy);

	vec.push_back(starting_state);
	Dstate * start = epsilon_closure(new Dstate(counter++,vec));
	vector<Dstate*> temp;
	temp.push_back(start);
	table.push_back(temp);
	for(int i = 0;i<table.size();i++){
		for(int j =0;j<inputs.size();j++){
			Dstate * tmp = epsilon_closure(move(table[i][0],inputs[j]));
			table[i].push_back(tmp);
		}

	}
	//for(int i =0;i<)
}
Transition_Table::~Transition_Table() {
	// TODO Auto-generated destructor stub
}

