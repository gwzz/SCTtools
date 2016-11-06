// C++ program to generate long DFS traversal from a given vertex in a  given graph
#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Pre-define hierarchy array
// CUI: array of top nodes concept id of each hierarchy
// ConName: array of the name of each hierarchy
const long long CUI[19] = {123037004, 404684003, 308916002, 272379006, 363787002, 410607006, 373873005, 78621006, 260787004, 71388002, 362981000, 419891008, 243796009, 900000000000441003, 48176007, 370115009, 123038009, 254291000, 105590001};
const string ConName[19] = {"Body_structure", "Clinical_finding", "Environment_or_geographical_location", "Event", "Observable_entity", "Organism", "Pharmaceutical_biologic_product", "Physical_force", "Physical_object", "Procedure", "Qualifier_value", "Record_artifact", "Situation_with_explicit_context", "SNOMED_CT_Model_Component", "Social_context", "Special_Concept", "Specimen", "Staging_and_scales", "Substance"};

// define global variables
// nodeMap: store all the concepts [key,value]
// reversedNodeMap: store reversed nodeMap [value,key]
// nodeFile, relationFile, outputFile, as variable name

std::map<long long, int> nodeMap;
std::map<int, long long> reversedNodeMap;
string nodeFile = "2016nodes.txt";
string relationFile = "2016relation.txt";
string outPutFolder = "/Users/zhuwei/Desktop/sct_nodes_within_hierarchy/";
std::vector<long long> outPutVec;
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    long long V;    
    list<long long> *adj;   
    void DFSUtil(long long v, bool visited[]); 
public:
    Graph(long long V);   
    void addEdge(long long v, long long w);  
    void DFS(long long v);   
};

Graph::Graph(long long V)
{
    this->V = V;
    adj = new list<long long>[V];
}
 
void Graph::addEdge(long long v, long long w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(long long v, bool visited[])
{
    visited[v] = true;
    // output to terminal
    // cout << reversedNodeMap[v] << " ";
    
    // output to file
    outPutVec.push_back(reversedNodeMap[v]);
    list<long long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
void Graph::DFS(long long v)
{
    bool *visited = new bool[V];
    for (long long i = 0; i < V; i++)
        visited[i] = false;
 
    DFSUtil(v, visited);
}

// string split function: split(s,d)
// input: s: string, d: delimiter
// output: a vector of splitted strings
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<long long> split(const string &s, char delim) {
    vector<string> elems;
    vector<long long> res;
    split(s, delim, elems);
    for(auto i : elems){
        res.push_back(std::stoll(i));
    }
    return res;
}
 
int main()
{
    
    long long topNode;
    // cin >> outputFile >> topNode;
    string sline;
    vector<string> relation;
    std::vector<string> nodes;

    fstream fin;
    fin.open(nodeFile,ios::in);
    while (getline(fin, sline)){
        nodes.push_back(sline);
    }
    fin.close();
    for (int i = 0; i < nodes.size(); ++i){
        nodeMap[std::stoll(nodes[i])] = i;
    }

    for (map<long long, int>::iterator i = nodeMap.begin(); i != nodeMap.end(); ++i)
        reversedNodeMap[i->second] = i->first;

    int nodeSize = nodeMap.size();
    fin.open(relationFile,ios::in);
    while (getline(fin, sline)){
        relation.push_back(sline);
    }
    fin.close();
    Graph g(nodeSize);
    std::vector<long long> vres;
    for (auto i : relation){
        vres.clear();
        vres = split(i, ',');
        g.addEdge(nodeMap[vres[1]],nodeMap[vres[0]]);
    }
    // g.addEdge(1, 2);
    // g.DFS(nodeMap[vres[0]]);
    // g.DFS(nodeMap[105590001]);
    string outPutFile;
    for (int i = 0; i < 19; ++i){
        outPutVec.clear();
        outPutFile.clear();
        outPutFile = outPutFolder + ConName[i];
        topNode = CUI[i];
        g.DFS(nodeMap[topNode]);
        fstream fout;
        fout.open(outPutFile,ios::app);
        for (auto o : outPutVec){
            fout << o << endl;
        }
        fout.close();
        // cout << outPutVec.size() << endl;
    }
 
      return 0;
}