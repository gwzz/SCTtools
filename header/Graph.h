#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
class Graph
{
    long long V;
    std::list<long long> *adj;
    std::vector<long long> return_path_; 
    void DFSUtil(long long v, bool visited[]); 
public:
    Graph(long long V);   
    void addEdge(long long v, long long w);  
    std::vector<long long> DFS(long long v);   
};

#endif