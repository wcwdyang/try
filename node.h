#ifndef NODE
#define NODE
template <class T>
class Node
{
  private: T value;
           int height;
           Node<T>* left;
           Node<T>* right;
  public:  Node();
           Node(T,Node<T>*,Node<T>*,int);
           ~Node();
           T get();
           int& getheight();
           Node<T>*& getleft();
           Node<T>*& getright();
           void setvalue(T t);
           void setleft(Node* l);
           void setright(Node* r);
           void setheight(int i);


};
template <class T>
void Node<T>::setvalue(T t)
{
    value =t;
}
template <class T>
void Node<T>::setleft(Node<T> *l)
{
 left = l;
}
template <class T>
void Node<T>::setright(Node<T> *r)
{
    right =r;
}
template <class T>
void Node<T>::setheight(int i)
{
    height = i;
}

template <class T>
Node<T>::Node()
{
    left = NULL;
    right=NULL;
    height =0;
}
template <class T>
Node<T>::Node(T t,Node<T>* left=NULL,Node<T>*right=NULL,int h=0):value(t),left(left),right(right),height(h)
{

}
template <class T>
Node<T>::~Node()
{
    delete left;
    delete right;
}
template <class T>
T Node<T>::get()
{
  return value;
}
template <class T>
Node<T>*& Node<T>::getleft()
{
    return left;
}
template <class T>
Node<T>*& Node<T>::getright()
{
     return right;
}
template <class T>
int& Node<T>::getheight()
{
    return height;
}

#endif // NODE

