#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree tree;
    int n=10;
    tree.SetRoot(15);
    for(int i=n;i<(n<<1);i++)
    {
        tree.AddNode(i);
    }
    tree.PostOrder();
    tree.LRD();
    return 0;
}