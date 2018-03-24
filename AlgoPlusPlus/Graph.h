#pragma once
#include <iostream>
#include <set>

using namespace std;

class Graph {
public:
	Graph(int nodes);
	~Graph();
	bool AddEdge(int u, int v);
	void BFS(int starting_node);
	void DFS(int starting_node);


private:
	void DFSRec(set<int>* s, int current_node);

	bool **m_Map;
	int m_Size;
};