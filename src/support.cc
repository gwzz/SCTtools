#include "support.h"

// string split function: split(s,d)
// input: s: string, d: delimiter
// output: a vector of splitted strings
void Split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<long long> Split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::vector<long long> res;
  Split(s, delim, elems);
  for(auto i : elems){
    res.push_back(std::stoll(i));
  }
  return res;
}