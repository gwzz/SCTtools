#ifndef SCTTOOLS_GRAPH_H_
#define SCTTOOLS_GRAPH_H_

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

#endif // SCTTOOLS_GRAPH_H_