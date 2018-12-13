#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "intersection.h"

using namespace std;

intersection::intersection(vector<int> accepting1,vector <vector<int> > trans1,vector<int> accepting2,vector<vector<int> > trans2){
	accept1 = accepting1;
	tran1 = trans1;
	accept2 = accepting2;
	tran2 = trans2;
}
void intersection::numberOfStates(){
	cout << "Number of states: " << (tran1.size())*(tran2.size()) << endl;
}


void intersection::newTran(vector<char> alph){

//	cout << "Accepting states: ";
	vector<int> store;
	vector<vector<int> > tran3;
	tran3.resize((tran1.size())*(tran2.size()));
	int index = 0;
	int count = 1;
//	cout << "tran1[0].at(3)" << tran1[3].at(0) << endl;
//	cout <<"tran[0].size(): " <<  tran1[0].size() << endl;
	for(unsigned int i = 0; i < tran1[0].size(); i++){ //run through number of rows
			int cnt = 0;
			while(cnt < tran1.size()*tran2.size()){
				for(unsigned int k = 0; k < tran2.size(); k++){ //run through second tran states
	/*		cout << "count: " << count << endl;
			count++;
			cout << "tran[index].at(i)" << tran1[index].at(i) << endl;
			cout << "tran2[[k].at(1): " << tran2[k].at(i) << endl;
	*///		cout << "i: " << i << endl;
			tran3[cnt].push_back((tran1[index].at(i) * tran2.size()) + tran2[k].at(i));

			for(unsigned int j = 0; j < accept1.size();j++){
				for(unsigned int w = 0; w < accept2.size();w++){
			if(tran1[index].at(i) == accept1[j] && tran2[k].at(i) == accept2[w]){
				store.push_back(tran3[cnt][i]);
				}
				}
			}
			cnt++;
				}	
			index++;
			}
	index = 0;
	}
	cout << "Accepting states: ";
	sort(store.begin(),store.end());
	bool removeSpace = true;
	for(unsigned int i = 0; i < store.size();i++){
		while(i < store.size()-1 && store[i] == store[i+1]){
		i++;
		}
		if(removeSpace){
		cout << store[i];
		removeSpace = false;
		}else{	
		cout << " " << store[i];
		}
	}
	
	cout << endl;
	
        cout << "Alphabet: ";
        for(int i = 0; i < alph.size();i++){
                cout << alph[i];
        }
	cout << endl;
	bool spaces = true;
	for(unsigned int i = 0; i < tran3.size();i++){
		spaces = true;
		for(unsigned int j = 0;j < tran3[i].size();j++){
		if(spaces){
			cout << tran3[i][j];
			spaces = false;
		}else{
		cout << " " << tran3[i][j];
		}
		}
		cout << endl;
	}
}
