#include "sctfile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
SctFile::SctFile(std::string filename) {
  std::string line;
  std::ifstream myfile (filename);

  if (myfile.is_open()) {
  	// read in file into chunk
  	getline(myfile, line);
    while (getline (myfile, line)) {
      this->file_chunk.push_back(line);
    }
    myfile.close();
    std::set<std::string> temp_nodes;
    // extract out relations from chunk
    for (std::vector<std::string>::iterator it = file_chunk.begin(); it != file_chunk.end(); ++it) {
			std::vector<std::string> temp_token_vec;
	    std::istringstream iss(*it);
			std::string token;
			while (std::getline(iss, token, '\t')){   
		    temp_token_vec.push_back(token);
			}
			if (temp_token_vec[2] == "1" && temp_token_vec[7] == "116680003") {
				temp_nodes.insert(temp_token_vec[4]);
				temp_nodes.insert(temp_token_vec[5]);
				this->relations_.push_back(temp_token_vec[4] + "," + temp_token_vec[5]);
			}	
		}
		// extract nodes from relations
		this->nodes_.assign(temp_nodes.begin(),temp_nodes.end());		
  } else { 
     std::cout << "Unable to open file"; 
  }
}

std::vector<std::string>  SctFile::relations() {
	return relations_;
}

std::vector<std::string> SctFile::nodes() {
	return nodes_;
}

std::map<std::string, std::vector<std::string> > SctFile::attributes() {
	return attributes_;
}

std::map<std::string, std::vector<std::string> > SctFile::TrainstiveClosures() {
	return trainstive_closure_;
}