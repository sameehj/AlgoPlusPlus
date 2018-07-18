#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	set<int> nodes = { 1,2,3,4,5,6,7,8,9 };

	Graph<int> graph (nodes);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 2);
	graph.AddEdge(2, 4);
	graph.AddEdge(7, 2);
	graph.AddEdge(3, 6);
	graph.AddEdge(6, 2);

	Graph<int>::BFSiterator it = graph.begin(2);
	while (it.hasNext())
	{
		cout << it.getCurrent() << endl;
		it.next();
	}

	return 0;
}