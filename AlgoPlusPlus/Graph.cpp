#include "Graph.h"
#include <stdexcept>


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
