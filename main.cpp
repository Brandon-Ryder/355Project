/*
*Author: Brandon Ryder
*File: main.cpp
*Description:
*Input:
*Output:
*Date: Tue Nov 20 17:53:21 EST 2018
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#include "intersection.h"

using namespace std;

void complement(vector<int>,int);
int main(int argc,char *argv[]){
	
	//complement
	if(argc == 2){
	FILE *fp = fopen(argv[1], "r");
	
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
//                              cout << states;
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
fclose(fp);


        cout << "Number of states: " << states << endl;

        cout << "Accepting states: ";
	complement(accepting,states);
/*
        for(int i = 0; i < accepting.size(); i++){
                cout <<accepting[i] << " ";    
        }
*/

        cout << endl;
        cout << "Alphabet: ";
        for(int i = 0; i < alphabet.size();i++){
                cout << alphabet[i];
        }

	int space = 0;
        for(int i = 0; i < trans.size();i++){
                cout << endl;
		space = 0;
                for(int j = 0;j < trans[i].size();j++){
			if(space == 0){
             		   cout <<  trans[i][j];
			   space++;
			}else{
			   cout << " " << trans[i][j];
			}
                }
	 	
        }





	}else{
		//intersection
	FILE *first_DFA = fopen(argv[1], "r");
	FILE *second_DFA = fopen(argv[2], "r");
	
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

        while((c = fgetc(first_DFA)) != EOF){
                //switch denotes which line is being used       
                switch(count){
                //number of states
                case 0:
                        {
                        //find the number of states
                        while((c = fgetc(first_DFA)) != '\n'){
                                if(c >= 48 && c <= 57){
                                states = states*10;
                                states += (c-'0');
//                              cout << states;
				}
                        }
                        count++;
                        trans.resize(states);
                        }
                case 1:
                        {
                        int sum = 0;
                        //navigate untill you reach the list of accepted states
                        while(sum < 18){
                                c = fgetc(first_DFA);
                                sum++;
                                }
                        //gather accepted states until end of line
                        int accept = 0;
                        while((c = fgetc(first_DFA)) != '\n'){
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
                                c = fgetc(first_DFA);
                                add++;
                                }
                        while(((c = fgetc(first_DFA)) != '\n') ){
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


	int count2 = 0;

        //DFA INFO
        int  states2 = 0;
        vector<int> accepting2;
        vector<char> alphabet2;
        vector <vector<int> >  trans2;
        int trans_count2 = 0;
        

        int row2 = 0;
        int col2 = -1; //hacky code to ignore a \n from the file
        int state_count2 = 0;

        while((c = fgetc(second_DFA)) != EOF){
                //switch denotes which line is being used       
                switch(count2){
                //number of states
                case 0:
                        {
                        //find the number of states
                        while((c = fgetc(second_DFA)) != '\n'){
                                if(c >= 48 && c <= 57){
                                states2 = states2*10;
                                states2 += (c-'0');
//                              cout << states;
				}
                        }
                        count2++;
                        trans2.resize(states2);
                        }
                case 1:
                        {
                        int sum = 0;
                        //navigate untill you reach the list of accepted states
                        while(sum < 18){
                                c = fgetc(second_DFA);
                                sum++;
                                }
                        //gather accepted states until end of line
                        int accept = 0;
                        while((c = fgetc(second_DFA)) != '\n'){
                                if(c != 32){
                                accept = accept*10;
                                accept += (c-'0');
                                }else{
                                accepting2.push_back(accept);
                                accept = 0;
                                }
                        }
                        accepting2.push_back(accept);
                        count2++;
                        }

 case 2:
                        {
                        int add = 0;
                        //get the alphabet
                        while(add < 10){
                                c = fgetc(second_DFA);
                                add++;
                                }
                        while(((c = fgetc(second_DFA)) != '\n') ){
                                alphabet2.push_back(c);
                                }
                        count2++;
                        }
                }
                //once the first three lines are read
                if(count >= 3){
                        //if not at the /n you need to continue concatinating           
                        if(c != '\n'){

                                if(c != ' '){
                                state_count2 = state_count2 * 10;
                                state_count2 += (c-'0');
                                }
                                if(c == ' '){
                                trans2[col2].push_back(state_count2);
                                row2++;
                                state_count2 = 0;
                                }

			 }else if(c == '\n'){
                           trans2[col2].push_back(state_count2);
                            row2 = 0;
                            col2++;
                            state_count2 = 0;
                 	       }
 
        	       }
		}

intersection output = intersection(accepting,trans,accepting2,trans2);
	output.numberOfStates();

/*
        cout << "Number of states: " << states << endl;

        cout << "Accepting states: ";
	complement(accepting,states);

        for(int i = 0; i < accepting.size(); i++){
                cout <<accepting[i] << " ";    
        }
        cout << endl;

        cout << "Alphabet: ";
        for(int i = 0; i < alphabet.size();i++){
                cout << alphabet[i];
        }
	cout << endl;

        for(int i = 0; i < trans.size();i++){
                cout << endl;
                for(int j = 0;j < trans[i].size();j++){
                cout <<  trans[i][j] << " ";
                }
        }



        cout << "Number of states: " << states2 << endl;

        cout << "Accepting states: ";

        for(int i = 0; i < accepting2.size(); i++){
                cout <<accepting2[i] << " ";    
        }
        cout << endl;

        cout << "Alphabet: ";
        for(int i = 0; i < alphabet2.size();i++){
                cout << alphabet2[i];
        }
        for(int i = 0; i < trans2.size();i++){
                cout << endl;
                for(int j = 0;j < trans2[i].size();j++){
                cout <<  trans2[i][j] << " ";
                }
        	}

*/
	output.newTran(alphabet);
	}
	return 0;
}

void complement(vector<int> accept, int state){
	bool curr = true;
	bool spaces = true;
	int count = 0;
	for(unsigned int i = 0; i < state;i++){
		for(unsigned int j = 0;  j < accept.size();j++){
		if(i == accept[j]){
		curr = false;
		}
		}
		if(curr){
			if(count == 0){
			cout  << i;
			count++;
			}else{
			cout << " " << i;
			}
		}
		curr = true;
	}
}
