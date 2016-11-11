#include "sctfile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>

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
    // extract out relations from chunk
    for (std::vector<std::string>::iterator it = file_chunk.begin(); it != file_chunk.end(); ++it) {
			std::vector<std::string> temp_token_vec;
	    std::istringstream iss(*it);
			std::string token;
			while (std::getline(iss, token, '\t')){   
		    temp_token_vec.push_back(token);
			}
			if (temp_token_vec[2] == "1" && temp_token_vec[7] == "116680003") {
				this->relations.push_back(temp_token_vec[4] + "," + temp_token_vec[5]);
			}	
		}
		// extract nodes from relations
		std::cout << this->relations.size() << std::endl;
  } else { 
     std::cout << "Unable to open file"; 
  }
}

std::vector<std::string>  SctFile::GetNodes() {
	std::vector<std::string> res;
	std::for_each(file_chunk.begin(), file_chunk.end(), [](std::string const& line) {
    std::istringstream iss(line);
		std::string token;
		while (std::getline(iss, token, '\t')){   
	    std::cout << token << "|";
		}
	});
	return res;
}

std::vector<std::string> SctFile::GetRelations() {
	std::vector<std::string> res;
	for (std::vector<std::string>::iterator it = file_chunk.begin(); it != file_chunk.end(); ++it) {
		std::vector<std::string> temp_token_vec;
    std::istringstream iss(*it);
		std::string token;
		while (std::getline(iss, token, '\t')){   
	    temp_token_vec.push_back(token);
		}
		if (temp_token_vec[2] == "1" && temp_token_vec[7] == "116680003") {
			res.push_back(temp_token_vec[4] + "," + temp_token_vec[5]);
		}	
	}
	this->relations = res;
	return res;
}