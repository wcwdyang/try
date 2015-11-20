#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include <iostream>
struct page
{
   std::vector<int> pagenum;
   std::vector<int> frequency;
};

class container
{
private:
    std::string s;
    page p;
public:
    container();
    ~container();
    friend bool operator<(const container &,const container&);
    friend bool operator>(const container&, const container&);
    friend bool operator==(const container&, const container&);
    container(std::string ,int,int);
    void setpage(int,int);
    page getpage();
    friend std::ostream& operator<<(std::ostream&,const container&);


};

#endif // CONTAINER_H
