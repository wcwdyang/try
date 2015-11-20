#ifndef QUERYPARSER_H
#define QUERYPARSER_H
#include <vector>
#include <container.h>

class queryparser
{

private:
    std::vector<int> p;
    std::string key;
public:
    queryparser();
    std::vector<int> AND(std::vector<int>&,std::vector<int> &);
    std::vector<int> OR(std::vector<int>&,std::vector<int>&);
    void clear();
    queryparser(std::string,std::vector<std::vector<int>>);
   std::vector<int> getp();

};

#endif // QUERYPARSER_H
