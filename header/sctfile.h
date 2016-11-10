#ifndef SCTTOOLS_SCTFILE_H_
#define SCTTOOLS_SCTFILE_H_

#include <vector>
#include <string>
#include <map>
class SctFile
{
    std::vector<std::string> file_chunk;
    std::vector<std::string> relations;
    std::vector<std::string> nodes;
public:
    SctFile(std::string filename);
    std::vector<std::string> GetNodes();
    std::vector<std::string> GetRelations();
};
#endif // SCTTOOLS_SCTFILE_H_