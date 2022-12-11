#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <map>
#include "TSP.h"
using namespace std;

TSP::TSP(int inputNodes=100) {
	nodes = inputNodes;
	edges_list = new int* [nodes + 1];

	//set table with weights to 0
	

}

/*
void TSP::christofides() {
	vector< vector< int > > Gedges_vec = edges_vec;
	vector< vector< int > > T;
	vector< vector< int > > S;
	vector< vector< int > > M;
	vector< vector< int > > G;
	int cost = 0, currEdges = 0, a1, a2, b1, b2;
	int* visited = new int[nodes + 1];
	int* path = new int[nodes + 1];
	vector <int> temp = {-1);
	vector < vector<int> > connection;
	for (int i = 0; i <= nodes; i++) {
		connection.push_back(temp);
	}
	for (int i = 0; i <= nodes; i++) {
		path[i] = -1;
		visited[i] = 0;
	}
	sort(edges_vec.begin(), edges_vec.end(),
		[](const vector<int>& a, const vector<int>& b) {
			return a[2] > b[2];
		});


	bool c1, c2, c3, c4;
	int checkNode;
	while (!edges_vec.empty() && currEdges < nodes) {
		temp = edges_vec.back();
		edges_vec.pop_back();
		cout << "edge i koszt :" << temp[0] << " " << temp[1] << " " << temp[2] << " \n";
		//cout << "wektor polaczen dla 1:" << connection[temp[0]][0] << " " << connection[temp[0]].second << "\n";
		//cout << "wektor polaczen dla 2:" << connection[temp[1]].first << " " << connection[temp[1]].second << "\n";

		c1 = c2 = c3 = c4 = 0;
		//for all
		//MAKE MST

		//last edge
		if (currEdges == nodes - 1) {
			if (a1 == -1 || a2 == -1 || b1 == -1 || b2 == -1) {
				cout << "xxxx: " << c1 << c2 << c3 << c4 << "\n";
				if (a2 != -1) c1 = isCycleCH(temp[1], temp[0], a2, connection);
				if (a1 != -1) c2 = isCycleCH(temp[1], temp[0], a1, connection);
				if (b1 != -1) c3 = isCycleCH(temp[0], temp[1], b1, connection);
				if (b2 != -1) c4 = isCycleCH(temp[0], temp[1], b2, connection);
				cout << "xxxx: " << c1 << c2 << c3 << c4 << "\n";
				if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) { //no cycle
					if (connection[temp[0]].first == -1) connection[temp[0]].first = temp[1];
					else connection[temp[0]].second = temp[1];
					if (connection[temp[1]].first == -1) connection[temp[1]].first = temp[0];
					else connection[temp[1]].second = temp[0];
					cost += temp[2];
					cout << "yeah, can make it \n";
					currEdges++;
				}
				else cout << "make cycle, oh no\n";
			}
		}
			//clean nodes
			else if (a1 == -1 && a2 == -1 && b1 == -1 && b2 == -1) {
				connection[temp[0]].first = temp[1];
				connection[temp[1]].first = temp[0];
				cost += temp[2];
				cout << "all clear can connect \n";
				currEdges++;
			}
			else {
				cout << "xxxx: " << c1 << c2 << c3 << c4 << "\n";
				if (a2 != -1) c1 = isCycleCH(temp[1], temp[0], a2, connection);
				if (a1 != -1) c2 = isCycleCH(temp[1], temp[0], a1, connection);
				if (b1 != -1) c3 = isCycleCH(temp[0], temp[1], b1, connection);
				if (b2 != -1) c4 = isCycleCH(temp[0], temp[1], b2, connection);
				cout << "xxxx: " << c1 << c2 << c3 << c4 << "\n";
				if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) { //no cycle
					if (connection[temp[0]].first == -1) connection[temp[0]].first = temp[1];
					else connection[temp[0]].second = temp[1];
					if (connection[temp[1]].first == -1) connection[temp[1]].first = temp[0];
					else connection[temp[1]].second = temp[0];
					cost += temp[2];
					cout << "yeah, can make it \n";
					currEdges++;
				}
				else cout << "make cycle, oh no\n";


			}
			temp.clear();
			cout << "===========\n";
			for (int i = 1; i <= nodes; i++) {
				cout << i << " wektor polaczen : " << connection[i].first << " " << connection[i].second << "\n";
			}
			cout << "===========\n";
		
	}
	cout << "cost christo : " << cost << "\n";

}
bool TSP::isCycleCH(int n, int b, int x, vector<vector<int> > vec) {
	cout << "new node: " << n << ", checkin now: " << x << "\n";
	if (x == n) return true;
	else if (vec[x].first != -1 && vec[x].second != -1) {
		if (vec[x].first != b) return isCycle(n, x, vec[x].first, vec);
		else return isCycle(n, x, vec[x].second, vec);
	}
	else return false;
}
*/
int TSP::greedy() {
	//da
	vector< vector< int > > Gedges_vec = edges_vec;
	vector <int> temp;
	vector < pair<int, int> > connection;
	int cost = 0, currEdges = 0, a1, a2, b1, b2;
	int* visited = new int[nodes + 1];
	int* path = new int[nodes + 1];

	for (int i = 0; i <= nodes; i++) {
		connection.push_back(make_pair(-1, -1));
	}
	for (int i = 0; i <= nodes; i++) {
		path[i] = -1;
		visited[i] = 0;
	}
	sort(edges_vec.begin(), edges_vec.end(),
		[](const vector<int>& a, const vector<int>& b) {
			return a[2] > b[2];
		});


	bool c1, c2, c3, c4;
	while (!edges_vec.empty() && currEdges < nodes) {
		temp = edges_vec.back();
		edges_vec.pop_back();
		a1 = connection[temp[0]].first;
		a2 = connection[temp[0]].second;
		b1 = connection[temp[1]].first;
		b2 = connection[temp[1]].second;
		c1 = c2 = c3 = c4 = 0;
		//for all
		if (currEdges == nodes - 1) {
			if ((a1 != -1 && a2 != -1) || (b1 != -1 && b2 != -1)) {
				//cant connect, one or two nodes full
			}
			else {
				cost += temp[2];
				currEdges++;
			}
		}
		else if (a1 == -1 && a2 == -1 && b1 == -1 && b2 == -1) {
			connection[temp[0]].first = temp[1];
			connection[temp[1]].first = temp[0];
			cost += temp[2];
			currEdges++;
		}
		else if ((a1 != -1 && a2 != -1) || (b1 != -1 && b2 != -1)) {
			//cant connect, one or two nodes full
		}
		//for temp 0 
		else if (a1 == -1 || a2 == -1 || b1 == -1 || b2 == -1) {
			if (a2 != -1) c1 = isCycle(temp[1], temp[0], a2, connection);
			if (a1 != -1) c2 = isCycle(temp[1], temp[0], a1, connection);
			if (b1 != -1) c3 = isCycle(temp[0], temp[1], b1, connection);
			if (b2 != -1) c4 = isCycle(temp[0], temp[1], b2, connection);
			if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) { //no cycle
				if (connection[temp[0]].first == -1) connection[temp[0]].first = temp[1];
				else connection[temp[0]].second = temp[1];
				if (connection[temp[1]].first == -1) connection[temp[1]].first = temp[0];
				else connection[temp[1]].second = temp[0];
				cost += temp[2];
				currEdges++;
			}

		}
		temp.clear();
	}
	return cost;

}
bool TSP::isCycle(int n, int b, int x, vector<pair<int, int> > vec) {
	if (x == n) return true;
	else if (vec[x].first != -1 && vec[x].second != -1) {
		if (vec[x].first != b) return isCycle(n, x, vec[x].first, vec);
		else return isCycle(n, x, vec[x].second, vec);
	}
	else return false;
}

int TSP::brutalForce()  {

	/// Picking a source city
	int s = 0;
	int V = nodes;
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight 
	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += edges_list[k][vertex[i]];
			k = vertex[i];

		}
		current_pathweight += edges_list[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;

}

int TSP::NN() {

	
	int min_e, current_e, next=666;
	int V = nodes;
	int *visited = new int [V];
	
	for (int i = 0; i < V; i++)
			visited[i] = 0;
	visited[0] = 1;

	int min_path = INT_MAX;
		int current_pathweight = 0;

		// compute current path weight
		int k = 0;
		for (int i = 0; i < nodes-1; i++) {
			min_e = INT_MAX;
			for (int j = 0; j < nodes; j++) {				
				if (visited[j] == 0 && edges_list[k][j] < min_e && k!=j) {
					min_e = edges_list[k][j];
					next = j;
				}
				
			}
			current_pathweight += min_e;
			k = next;
			visited[k] = 1;

		}
		current_pathweight += edges_list[k][0];

		delete[] visited;

		return current_pathweight;

}

void TSP::GenRandomGraphs()
{
	//data
	int n, e, i = 0, j, a, b, c, first_node, second_node, weight;;
	vector <int> temp;
	vector< vector< int > > vec;
	//random devices
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> distN(3, 10);
	nodes >= 3 ? n = nodes : n = distN(mt);
	nodes = n;
	e = (n * (n - 1)) / 2;
	uniform_real_distribution<double> distR(1, n + 1);
	uniform_real_distribution<double> distW(1, 100);

	for (int i = 0; i <= n; i++)
	{
		edges_list[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
		{
			edges_list[i][j] = 0;
		}
	}

	while (i < e) {
		do {
			a = distR(mt);
			b = distR(mt);
			c = distW(mt);

		} while (a == b);
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);

		vec.push_back(temp);
		temp.clear();

		for (j = 0; j < i; j++) {
			if ((vec[i][0] == vec[j][0] && vec[i][1] == vec[j][1]) || (vec[i][0] == vec[j][1] && vec[i][1] == vec[j][0]) && e > 2) {
				i--;
				vec.pop_back();
			}
		}
		i++;
	}

	edges_vec = vec;

	for (int i = 0; i < e; i++)
	{
		if (!vec.empty()) temp = vec.back();
		vec.pop_back();
		first_node = temp[0];
		second_node = temp[1];
		weight = temp[2];
		temp.clear();
		edges_list[first_node - 1][second_node - 1] = weight;
		edges_list[second_node - 1][first_node - 1] = weight;
	}
	nodes = n;
	vec.clear();
	temp.clear();
}

void TSP::showGraph() {
	cout << "\nThe generated random random graph is: ";
	for (int i = 0; i < nodes; i++)
	{
		int count = 0;
		cout << "\n\t" << i + 1 << "-> { ";
		for (int j = 0; j < edges_vec.size(); j++)
		{
			if (edges_vec[j][0] == i + 1)
			{
				cout << edges_vec[j][1] << "(" << edges_vec[j][2] << ")  ";
				count++;
			}
			else if (edges_vec[j][1] == i + 1)
			{
				cout << edges_vec[j][0] << "(" << edges_vec[j][2] << ")  " << "   ";
				count++;
			}
			else if (j == edges_vec.size() - 1 && count == 0)
				cout << "Isolated Vertex!";
		}

		cout << " } \n";
	}
}