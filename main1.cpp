/*
*Author: Brandon Ryder
*File: main.cpp
*Description:
*Input
*Output
*Date: Tue Nov 6 19:54:21 EST 2018
*/


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


#include "simDFA.h"

using namespace std;
int main(int argc,char *argv[]){


	//FILE IO	
	FILE *fp = fopen(argv[1], "r");
	FILE *sim_input = fopen(argv[2], "r");
	
	if(fp == NULL)
		return 1;
	if(sim_input == NULL)
		return 2;
	int count = 0;	
	
	//DFA INFO
	int  states = 0;
	vector<int> accepting;
	vector<char> alphabet;
	vector <vector<int> >  trans;
	int trans_count = 0;
	char c;

	int row = 0;
	int col = -1; //hacky code to ignore a \n from the file
	int state_count = 0;
	//read the number of states, accepting and alphabet
	while((c = fgetc(fp)) != EOF){
		//switch denotes which line is being used	
		switch(count){
		//number of states
		case 0:
			{
			//find the number of states
			while((c = fgetc(fp)) != '\n'){
				if(c >= 48 && c <= 57){
				states = states*10;
				states += (c-'0');

//				cout << states;
				}
			}
			count++;	
			trans.resize(states+1);
	 		}
		case 1:
			{
			int sum = 0;
			//navigate untill you reach the list of accepted states
			while(sum < 18){	
				c = fgetc(fp);
				sum++;
				}
			//gather accepted states until end of line
			int accept = 0;
			while((c = fgetc(fp)) != '\n'){
				if(c != 32){
				accept = accept*10;
				accept += (c-'0');
				}else{
				accepting.push_back(accept);
				accept = 0;
				}
			}
			accepting.push_back(accept);
			count++;
			}
		case 2:	
			{
			int add = 0;
			//get the alphabet
			while(add < 10){
				c = fgetc(fp);	
				add++;
				}
			while(((c = fgetc(fp)) != '\n') ){
				alphabet.push_back(c);
				}	
			count++;
			}	
		}
		//once the first three lines are read
		if(count >= 3){
			//if not at the /n you need to continue concatinating		
			if(c != '\n'){

				if(c != ' '){
				state_count = state_count * 10;
				state_count += (c-'0');	
				}
			 	if(c == ' '){	
				trans[col].push_back(state_count);
				row++;
				state_count = 0;
				}
			}else if(c == '\n'){
				trans[col].push_back(state_count);
				row = 0;
				col++;
				state_count = 0;
			}
		}
}
	
	//SIM READ
	vector<char> sim; //vector will hold each val and the \n

	while((c = fgetc(sim_input)) != EOF){
		sim.push_back(c);	
	}	
/*
	cout << "number of states: " << states << endl;
	cout << "accepting: " << endl;
	for(int i = 0; i < accepting.size(); i++){
		cout <<accepting[i]; 	
	}
	cout << endl;

	cout << "alphabet: " << endl;
	for(int i = 0; i < alphabet.size();i++){
		cout << alphabet[i];
	}

	cout << endl;
	cout << "trans: ";
	for(int i = 0; i < trans.size();i++){
		cout << endl;
		for(int j = 0;j < trans[i].size();j++){
		cout <<  trans[i][j] << " ";
		}
	}

	cout << endl;
	cout << "test for sim: " << endl;
	for(int i = 0; i < sim.size();i++){
	//	cout << sim[i] << endl;
	}
*/
	fclose(fp);
	fclose(sim_input);
	simDFA send_obj(accepting,alphabet,trans,sim);
	send_obj.findState();
	return 0;
}

