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
      while (getline (myfile, line)) {
        this->file_chunk.push_back(line);
      }
      myfile.close();
  } else { 
     std::cout << "Unable to open file"; 
  }
}

std::vector<std::string>  SctFile::GetNodes() {
	std::vector<std::string> res;
	for (auto x : file_chunk){
		std::cout << x << std::endl;
	}
	return res;
}