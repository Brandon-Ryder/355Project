
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include <iostream>

using namespace std;

class intersection {

	public:
	intersection(vector<int> accepting1,vector <vector<int> > trans1, vector<int> accepting2,vector<vector<int> > trans2);
	void numberOfStates();
	void newTran(vector<char> alph);
	
	private:
	vector<int> accept1;
	vector<vector<int> > tran1;
	vector<int> accept2;
	vector<vector<int> > tran2;
};
#endif

