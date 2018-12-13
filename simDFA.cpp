#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#include "simDFA.h"

using namespace std;




simDFA::simDFA(vector<int> accepting, vector<char> alphabet,vector <vector<int> > trans, vector<char> sim){
	accept = accepting;
	alph   = alphabet;
	tran = trans;
	dfa_sim = sim;
}	

void simDFA::findState(){
		//iterate through dfa_sim vector
	int tester = 0;
	int next_state = 0;
	for(int i = 0; i < dfa_sim.size();i++){
		int curr = 0;
		//make the int curr line into a function call
		if((dfa_sim[i] - '0') == -38){

		bool test = false;
		for(unsigned int j = 0; j < accept.size();j++){
			if(next_state == (accept[j])){
			test = true;	
			}
		}
			if(test == true){	
				cout << "accept" << endl;			
				tester++;
			}else{
				cout << "reject" << endl;
				tester++;
			}
			next_state = 0;
		}else{
//		cout << "alph value: " << dfa_sim[i] << endl;
		curr = getInt(dfa_sim[i]); // make an int
//		cout << "state before: " << next_state << endl; 
//		cout << "curr: " << curr << endl;
		next_state = tran[next_state][curr];
//		cout << "state after: " << next_state << endl; 
		}
	
	}
}
int simDFA::getInt(char alph_letter){
	for(unsigned int k =0; k < alph.size();k++){
		if(alph_letter == alph[k]){
			//return the value of alph index
			return k;
		}
	}
}




