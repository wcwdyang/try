#include <iostream>
#include "indexstruct.h"
#include "avltree.h"
using namespace std;

int main()
{
      AvlTree<int> avl;
      avl.insert(1);
      avl.insert(2);
      avl.insert(3);
      avl.insert(4);
      avl.insert(5);
      avl.insert(6);
     avl.inorder();
    cout << "Hello World!" << endl;
    return 0;
}

