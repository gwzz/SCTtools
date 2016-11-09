#ifndef SCTTOOLS_SCTFILE_H_
#define SCTTOOLS_SCTFILE_H_

#include <vector>
#include <string>
#include <map>
class SctFile
{
    std::vector<std::string> file_chunk; 
public:
    SctFile(std::string filename);
    std::vector<std::string> GetNodes();
};
#endif // SCTTOOLS_SCTFILE_H_