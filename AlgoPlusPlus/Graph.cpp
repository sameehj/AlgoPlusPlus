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
		for (int j = 0; j < m_Size; j++)
		{
			m_Map[i][j] = false;
		}
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

void print_queue(queue<int> q, int start = 0, int end = 1000)
{
	int i = 0;
	while (!q.empty() && i < end)
	{
		if (i >= start)
		{
			std::cout << q.front() << " ";
		}
		q.pop();
		i++;
	}
	std::cout << std::endl;
}

void print_queue_layers(queue<int> q)
{
	int i = 0;
	int j = 0;

	while (!q.empty())
	{
		if (q.front() == -1)
		{
			q.pop();
			if (q.empty())
			{
				break;
			}
			cout << endl << " LeveL " << j++ << ":" << endl;
		}

		std::cout <<q.front() << " ";
		q.pop();
		i++;
	}
	std::cout << std::endl;
}

void Graph::BFS(int starting_node)
{
	queue<int> q;
	queue<int> layers_q;
	int i;
	int current_node;
	bool *visited;
	int current_layer_count = 0;
	int last_layer_count = 0;

	if (starting_node <= 0 || starting_node > m_Size)
	{
		throw std::exception("Illegal value for starting node");
	}
	visited = new bool[m_Size];
	for (i = 0; i < m_Size; i++)
	{
		visited[i] = false;
	}

	q.push(starting_node);
	layers_q.push(-1);
	layers_q.push(starting_node);
	layers_q.push(-1);
	last_layer_count = 1;
	current_layer_count = 0;
	visited[starting_node] = true;

	do {
		current_node = q.front();
		q.pop();
		for (i = 0; i < m_Size; i++)
		{
			if (m_Map[current_node][i] && !visited[i])
			{
				q.push(i);
				current_layer_count++;
				layers_q.push(i);
				visited[i] = true;
			}
		}

		last_layer_count--;

		if (last_layer_count == 0)
		{
			last_layer_count = current_layer_count;
			layers_q.push(-1);
		}
	} while (!q.empty());
	print_queue_layers(layers_q);
}
