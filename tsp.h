#pragma once
#include <vector>
#ifndef TSP_H
#define TSP_H

using namespace std; 
class TSP {
private:
	int** edges_list;
	int nodes;
	vector< vector< int > > edges_vec;
	bool isCycle(int n, int b, int x, vector<pair<int, int> > vec);


public:

	TSP(int inputNodes);
	
	//bool isCycleCH(int n, int b, int x, vector<vector<int > >vec);
	void GenRandomGraphs();
	int brutalForce();
	int NN();
	int greedy();
	//void christofides();
	void showGraph();



};

#endif // !TSP_H

