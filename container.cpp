#include "container.h"

container::container()
{
    s="null";

}
container::container(std::string s,int pagenum, int f)
{
    this->s=s;
    this->setpage(pagenum,f);
}
container::~container()
{

}
void container::setpage(int pagenum,int f)
{
    p.pagenum.push_back(pagenum);
    p.frequency.push_back(f);
}
bool operator<(const container& c,const container& c1)
{
    return c.s<c1.s;
}
bool operator>( const container& c,const container& c1)
{
    return c.s>c1.s;
}
bool operator==(const container& c,const container& c1)
{
    return c.s==c1.s;
}
std::ostream& operator<<(std::ostream& o,const container & c)
{
     o<<c.s;
  return o;
}
page container::getpage()
{
    return this->p;
}
