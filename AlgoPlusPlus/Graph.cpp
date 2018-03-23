#include "Graph.h"
#include <stdexcept>
#include <queue>

using namespace std;


Graph::Graph(int nodes) : m_Size(nodes)
{
	if (nodes <= 0)
	{
		throw std::exception("Illegal value for nodes");
	}
	
	m_Map = new bool*[nodes];
	for (int i = 0; i < nodes; ++i)
	{
		m_Map[i] = new bool[nodes];
	}
}

Graph::~Graph()
{
	for (int i = 0; i < m_Size; ++i)
	{
		delete m_Map[i];
	}
	delete m_Map;
}

bool Graph::AddEdge(int u, int v)
{
	if (v <= 0 || v > m_Size)
	{
		throw std::exception("Illegal value for starting node");
	}
	if (u <= 0 || u > m_Size)
	{
		throw std::exception("Illegal value for starting node");
	}
	if (m_Map[u][v])
	{
		return false;
	}
	m_Map[u][v] = true;
	return true;
}

void print_queue(queue<int> q)
{
	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

void Graph::BFS(int starting_node)
{
	queue<int> q;
	int j,i;
	int current_node;

	if (starting_node <= 0 || starting_node > m_Size)
	{
		throw std::exception("Illegal value for starting node");
	}

	q.push(starting_node);
	j = 0;
	do {
		cout << "layer " << j << ":" << endl;
		print_queue(q);
		j++;
		current_node = q.front();
		q.pop();
		for (i = 0; i < m_Size; i++)
		{
			if (m_Map[current_node][i])
			{
				q.push(i);
			}
		}
	} while (!q.empty());
}
