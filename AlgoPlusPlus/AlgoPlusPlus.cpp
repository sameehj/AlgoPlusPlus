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

	cout << "BFS iteration" << endl;
	Graph<int>::BFSiterator bfs_it = graph.begin(2);
	while (bfs_it.hasNext())
	{
		cout << bfs_it.getCurrent() << endl;
		bfs_it.next();
	}

	cout << "DFS iteration" << endl;
	Graph<int>::DFSiterator dfs_it = graph.beginDFS(2);
	while (dfs_it.hasNext())
	{
		cout << dfs_it.getCurrent() << endl;
		dfs_it.next();
	}

	return 0;
}