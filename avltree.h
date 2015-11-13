#ifndef AVLTREE
#define AVLTREE
#include "node.h"
#include <iostream>
template <class T>
class AvlTree
{
   private: Node<T>* root;
            void insert(T,Node<T>*&);
            void rotatecase1(Node<T>* &);
            void rotatecase2(Node<T>* &);
            void rotatecase3(Node<T>* &);
            void rotatecase4(Node<T>* &);
   public: AvlTree();
           AvlTree(const AvlTree & avl);
           ~AvlTree();
           bool isEmpty();
           void insert(T);
           void delet();
           int height(Node<T> *);
           int max(int,int);
           void inorder(Node<T>*);
           void inorder();


};
template <class T>
void AvlTree<T>::inorder()
{
    inorder(root);
}

template <class T>
void AvlTree<T>::inorder(Node<T> * node)
{
    if(node->getleft()==NULL&&node->getright()==NULL)
    {
        std::cout<<node->get()<<" ";
    }
    else
    {
        if(node->getleft()!=NULL)inorder(node->getleft());
        std::cout<<node->get()<<" ";
        if(node->getright()!=NULL)inorder(node->getright());
    }
}

template <class T>
AvlTree<T>::AvlTree()
{
    root = NULL;
}

template <class T>
bool AvlTree<T>::isEmpty()
{
    if(root==NULL) return true;
    else return false;
}
template <class T>
void AvlTree<T>::insert(T t)
{
    insert(t,root);
}
template <class T>
void AvlTree<T>::insert(T t,Node<T>*& node)
{
    if(node==NULL)
    {
        node = new Node<T>(t,NULL,NULL);
    }
    else
        if(t<node->get()) //left
        {
            insert(t,node->getleft());
            if(height(node->getleft())-height(node->getright())==2)
                if(t<node->getleft()->get())
                {
                    rotatecase1(node);
                }
            else rotatecase2(node);
        }
    else if(t>node->get())
        {
            insert(t,node->getright());
            if(height(node->getright())-height(node->getleft())==2)
                if(t>node->getright()->get())
                {
                    rotatecase4(node);
                }
            else rotatecase3(node);
        }

   node->setheight(max(height(node->getleft()),height(node->getright()))+1);

}
template <class T>
void AvlTree<T>::delet()
{
    delete root;
    root = NULL;
}
template <class T>
int AvlTree<T>::height(Node<T> * node)
{
    if(node == NULL) return 0;
    else
    return node->getheight();
}

template <class T>
void AvlTree<T>::rotatecase1(Node<T>*& node)
{
    Node<T> * temp = node->getleft();
    node->setleft(temp->getright());
    temp->setright(node);
    temp->setheight(max(height(temp->getleft()),height(temp->getright()))+1);
    node->setheight(max(height(node->getleft()),height(node->getright()))+1);
    node = temp;


}
template <class T>
void AvlTree<T>::rotatecase4(Node<T> *& node)
{
    Node<T> * temp = node->getright();
    node->setright(temp->getleft());
    temp->setleft(node);
    temp->setheight(max(height(temp->getleft()),height(temp->getright()))+1);
    node->setheight(max(height(node->getleft()),height(node->getright()))+1);
    node  = temp;

}
template <class T>
void AvlTree<T>::rotatecase2(Node<T> *& node)
{
    rotatecase4(node->getleft());
    rotatecase1(node);
}
template <class T>
void AvlTree<T>::rotatecase3(Node<T> *& node)
{
    rotatecase1(node->getright());
    rotatecase4(node);
}
template <class T>
int AvlTree<T>::max(int i1,int i2)
{
    if(i1>i2) return i1;
    if(i2>i1) return i2;
    if(i1==i2) return i1;
}

template <class T>
AvlTree<T>::~AvlTree()
{
    delete root;
}

#endif // AVLTREE

