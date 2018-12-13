
#ifndef SIMDFA_H
#define SIMDFA_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class simDFA {
	//constructor
	public:
	simDFA(vector<int> accepting, vector<char> alphabet,vector <vector<int> > trans, vector<char> sim);
	void findState();
	int getInt(char alph_letter);


	//member variables
	private:
	vector<int> accept;
	vector<char> alph;
	vector<vector<int> >  tran;
	vector<char> dfa_sim;
};
#endif
