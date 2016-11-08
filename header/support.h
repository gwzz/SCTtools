#ifndef SCTTOOLS_SUPPORT_H_
#define SCTTOOLS_SUPPORT_H_

#include <string>
#include <sstream>
#include <vector>


void Split(const std::string &s, char delim, std::vector<std::string> &elems);

std::vector<long long> Split(const std::string &s, char delim);

#endif // SCTTOOLS_SUPPORT_H_