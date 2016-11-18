/* author: @gwzz
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "graph.h"
#include "support.h"
#include "sctfile.h"

using namespace std;

// Pre-define hierarchy array
// CUI: array of top nodes concept id of each hierarchy
// ConName: array of the name of each hierarchy
const long long CUI[19] = {123037004, 404684003, 308916002, 272379006, 363787002, 410607006, 373873005, 78621006, 260787004, 71388002, 362981000, 419891008, 243796009, 900000000000441003, 48176007, 370115009, 123038009, 254291000, 105590001};
const string ConName[19] = {"Body_structure", "Clinical_finding", "Environment_or_geographical_location", "Event", "Observable_entity", "Organism", "Pharmaceutical_biologic_product", "Physical_force", "Physical_object", "Procedure", "Qualifier_value", "Record_artifact", "Situation_with_explicit_context", "SNOMED_CT_Model_Component", "Social_context", "Special_Concept", "Specimen", "Staging_and_scales", "Substance"};

// define global variables
// node_map: store all the concepts [key,value]
// reversed_node_map: store reversed node_map [value,key]
// nodeFile, relationFile, out_put_file, as variable name
string nodeFile = "2016nodes.txt";
string relationFile = "2016relation.txt";


 
int main(int argc, char* argv[])
{   
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " SNOMED_CT_FILE_PATH" << std::endl;
    return 1;
  }
  string out_put_folder = "/Users/zhuwei/Desktop/sct_nodes_within_hierarchy/";
  SctFile sf(argv[1]);
  long long top_node;
  std::map<long long, int> node_map;
  std::map<int, long long> reversed_node_map;
  std::vector<long long> output_vector;
  std::string sline;
  std::vector<std::string> relation = sf.relations();
  std::vector<std::string> nodes = sf.nodes();

    // Read in node file
  for (int i = 0; i < nodes.size(); ++i){
    node_map[std::stoll(nodes[i])] = i;
  }

  for (map<long long, int>::iterator i = node_map.begin(); i != node_map.end(); ++i)
    reversed_node_map[i->second] = i->first;

  int nodeSize = node_map.size();
  // initialize graph g
  Graph g(nodeSize);
  std::vector<long long> is_a_relationship;
  for (auto i : relation){
    is_a_relationship.clear();
    is_a_relationship = Split(i, ',');
    g.addEdge(node_map[is_a_relationship[1]],node_map[is_a_relationship[0]]);
  }

  string out_put_file;
  for (int i = 0; i < 19; ++i){
    output_vector.clear();
    out_put_file.clear();
    out_put_file = out_put_folder + ConName[i];
    top_node = CUI[i];
    output_vector = g.DFS(node_map[top_node]);
    fstream fout;
    fout.open(out_put_file,ios::app);
    for (auto o : output_vector){
        fout << reversed_node_map[o] << endl;
    }
    fout.close();
  }
 
    return 0;
}