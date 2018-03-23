#include <iostream>
#include "Graph.h"

using namespace std;

void ExampleGraphBFS()
{
	Graph g(10);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(1, 5);

	g.AddEdge(2, 4);
	g.AddEdge(2, 5);
	
	g.AddEdge(3, 5);
	g.AddEdge(3, 6);

	g.AddEdge(4, 5);
	g.AddEdge(4, 8);

	g.AddEdge(5, 6);

	g.AddEdge(6, 7);
	g.AddEdge(6, 9);

	g.AddEdge(7, 4);
	g.AddEdge(7, 5);
	g.AddEdge(7, 8);

	g.AddEdge(9, 7);
	g.AddEdge(9, 8);

	g.BFS(1);
}

int main()
{
	cout << "Hello World!" << endl;
	ExampleGraphBFS();
	return 0;
}