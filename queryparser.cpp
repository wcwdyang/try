#include "queryparser.h"

queryparser::queryparser()
{

}
std::vector<int> queryparser::getp()
{
    return p;
}

queryparser::queryparser(std::string s,std::vector<std::vector<int>> i)
{
    std::vector<int> temp;
    temp = i[0];
   if(s=="AND")
       for(int j=0;j<i.size();j++)
       {
          temp = AND (temp,i[j]);
          clear();

       }
     else
       if(s =="OR")
           for(int j=0;j<i.size();j++)
           {
               temp = OR(temp,i[j]);
               clear();
           }
    p=temp;
  // for(int j=0;j<temp.size();j++)
  // {
   //    std::cout<<temp[j]<<" ";
  // }
}
std::vector<int> queryparser::AND(std::vector<int> &c1,std::vector<int> & c2)
{
    for(int i=0;i<c1.size();i++)
    {
        for(int j=0;j<c2.size();j++)
        {
            if(c1[i]==c2[j])
                p.push_back(c1[i]);
        }
    }
    return p;
}
std::vector<int> queryparser::OR(std::vector<int>& c1,std::vector<int> & c2)
{
    for(int i=0;i<c1.size();i++)
    {
        p.push_back(c1[i]);
    }
    for(int i=0;i<c2.size();i++)
    {
        bool flag =false;
        for(int j=0;j<c1.size();j++)
        {
            if(c2[i]==c1[j])
                 flag = true;
        }
        if(!flag)
            p.push_back(c2[i]);
    }
        return p;
}
void queryparser::clear()
{
    p.clear();
}
