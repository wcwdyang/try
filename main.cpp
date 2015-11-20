#include <iostream>
#include "indexstruct.h"
#include "avltree.h"
#include "container.h"
#include "queryparser.h"
#include <stack>
using namespace std;
int test();
int test(int);
int main()
{
    AvlTree<container> avl;
    avl.insert(container("chu",3,1));
    avl.insert(container("jin",4,1));
    avl.insert(container("han",2,2));
    avl.insert(container("kena",3,3));
    avl.insert(container("yang",2,1));
    //std::cout<<avl.find(container("han",0,0));
     avl.inorder();

   //  std::cout<<avl.find(container("f",0,0));
   std::stack<std::vector<int>> s;
   std::stack<std::string> sk;
   std::string word,key;
   std::vector<std::vector<int>> i;
   std::vector<string> words;
   while(word!="q")
   {
     std::cin>>word;
 B:    if(word=="AND"||word=="OR")
     {
         key = word;
         word.clear();
         std::cin>>word;
         while(word!="AND"&&word!="OR"&&word!="q")
         {
             i.push_back(avl.find(container(word,0,0)).getpage().pagenum);
             std::cin>>word;
         }
         if(word=="AND"||word=="OR")
         {
             s.push(queryparser(key,i).getp());
             i.clear();
             sk.push(key);
         }
         else if(word =="q")
         {
             s.push(queryparser(key,i).getp());
             sk.push(key);
            while(!s.empty())
            {
             std::string tempk ;
             std::vector<int> temp = s.top();
             s.pop();
             sk.pop();
             if(s.empty())
             {
                 for(int j=0;j<temp.size();j++)
                 {
                     std::cout<<temp[j]<<" ";
                 }
             }
             else{
                  queryparser tempq;
                  tempk = sk.top();
                  if(tempk=="AND") tempq.AND(temp,s.top());
                  else if(tempk=="OR") tempq.OR(temp,s.top());
                  s.top() = tempq.getp();

                }
            }
         }
         goto B;

     }

   }
    cout << "Hello World!" << endl;
    return 0;
}
