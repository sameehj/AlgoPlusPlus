#pragma once

class Graph {
public:
	Graph(int nodes);
	~Graph();

private:
	bool **m_Map;
	int m_Size;
};