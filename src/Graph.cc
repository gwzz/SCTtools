#include "graph.h"

Graph::Graph(long long V)
{
    this->V = V;
    adj = new std::list<long long>[V];
}
 
void Graph::addEdge(long long v, long long w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(long long v, bool visited[])
{   
    std::vector<long long> res;
    visited[v] = true;
    return_path_.push_back(v);
    std::list<long long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
std::vector<long long> Graph::DFS(long long v)
{   
    return_path_.clear();
    bool *visited = new bool[V];
    for (long long i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    return return_path_;
}
