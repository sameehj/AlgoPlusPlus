#pragma once
#include <iostream>

class Graph {
public:
	Graph(int nodes);
	~Graph();
	bool AddEdge(int u, int v);
	void BFS(int starting_node);

private:
	bool **m_Map;
	int m_Size;
};