#include <cstdio>
#include <stack>
#include <queue>
#include "Tree.h"
#include <iostream>
using namespace std;

void Tree::MakeEmpty(TreeNode *T)
{
    if(!T->Right&&!T->Left)
    {
        delete T;
        return;
    }
    if(T->Left)
    {
        MakeEmpty(T->Left);
    }
    if(T->Right)
    {
        MakeEmpty(T->Right);
    }
}

Tree::Tree()
{
    T=new TreeNode;
}

Tree::~Tree()
{
    MakeEmpty(this->T);
}

void Tree::DLRDriver(const TreeNode * T)
{
    if(T)
    {
        cout<<T->key<<" ";
    }
    else
    {
        return;
    }
    if(T->Left)
    {
        DLRDriver(T->Left);
    }
    if(T->Right)
    {
        DLRDriver(T->Right);
    }
}

void Tree::LDRDriver(const TreeNode *T)
{
    if(!T)
    {
        return;
    }
    if(T->Left)
    {
        LDRDriver(T->Left);
    }
    cout<<T->key<<" ";
    if(T->Right)
    {
        LDRDriver(T->Right);
    }
}

void Tree::LRDDriver(const TreeNode *T)
{
    if(!T)
    {
        return;
    }
    if(T->Left)
    {
        LRDDriver(T->Left);
    }
    if(T->Right)
    {
        LRDDriver(T->Right);
    }
    cout<<T->key<<" ";
}

TreeNode* Tree::AddNodeDriver(int k, TreeNode* T)
{
    if(!T)
    {
        T=new TreeNode(k);
        return T;
    }
    else if(k<T->key)
    {
        T->Left=AddNodeDriver(k,T->Left);
    }
    else if(k>T->key)
    {
        T->Right=AddNodeDriver(k,T->Right);
    }
}

TreeNode* Tree::FindNodeDriver(int k, TreeNode* T)
{
    if(!T)
    {
        return NULL;
    }
    if(T->key==k)
    {
        return T;
    }
    else if(k<T->key)
    {
        return FindNodeDriver(k,T->Left);
    }
    else if(k>T->key)
    {
        return FindNodeDriver(k,T->Right);
    }
}

void Tree::LRD()
{
    LRDDriver(this->T);
    cout<<endl;
}

void Tree::LDR()
{
    LDRDriver(this->T);
    cout<<endl;
}

void Tree::DLR()
{
    DLRDriver(this->T);
    cout<<endl;
}

void Tree::AddNode(int k)
{
    AddNodeDriver(k,this->T);
}

void Tree::DeleteNode(int k)
{
    this->T=DeleteNodeDriver(k,this->T);
}

TreeNode* Tree::FindNode(int k)
{
    FindNodeDriver(k,this->T);
}

TreeNode* Tree::DeleteNodeDriver(int k, TreeNode* T)
{
    if(!T)//The node doesn't exist
    {
        return NULL;
    }
    else if(k<T->key)
    {
        T->Left=DeleteNodeDriver(k,T->Left);
    }
    else if(k>T->key)
    {
        T->Right=DeleteNodeDriver(k,T->Right);
    }
    else if(!(T->Left&&T->Right))//zero or one child
    {
        TreeNode* temp=T;
        if(!T->Right)//T->Right==NULL
        {
            T=T->Left;
        }
        else if(!T->Left)//T->Left==NULL
        {
            T=T->Right;
        }
        delete temp;
    }
    else
    {
        TreeNode* max=FindMaxDriver(T->Left);
        T->key=max->key;
        T->Left=DeleteNodeDriver(max->key,T->Left);
    }
    return T;
}

void Tree::SetRoot(int k)
{
    T->key=k;
}

TreeNode* Tree::FindMaxDriver(TreeNode *T)
{
    if(!T)
    {
        return NULL;
    }
    if(T->Right)
    {
        FindMaxDriver(T->Right);
    }
    else
    {
        return T;
    }
}

int Tree::FindMax()
{
    TreeNode* temp=FindMaxDriver(this->T);
    if(temp)
    {
        return temp->key;
    }
    else
    {
        return 0x80000000;
    }
}

void Tree::LevelTraversal()
{
    TreeNode* temp;
    queue<TreeNode*> Q;
    if(this->T)
    {
        Q.push(T);
    }
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        cout<<temp->key<<" ";
        if(temp->Left)
        {
            Q.push(temp->Left);
        }
        if(temp->Right)
        {
            Q.push(temp->Right);
        }
    }

}

void Tree::InOrder()const
{
    TreeNode* temp=this->T;//遍历指针
    stack<TreeNode*> S;
    do
    {
        while(temp)//遍历指针向左下移动
        {
            S.push(temp);//该子树沿途结点进栈
            temp=temp->Left;
        }
        if(!S.empty())//栈不空时退栈
        {
            temp=S.top();
            S.pop();//退栈
            cout<<temp->key<<" ";//访问
            temp=temp->Right;//遍历指针进到右子树
        }
    }while(temp||!S.empty());
    cout<<endl;
}

void Tree::PreOrder2() const
{
    stack<TreeNode*>S;
    TreeNode* temp=this->T;
    S.push(NULL);
    while(temp)
    {
        cout<<temp->key<<" ";// 访问结点
        if(temp->Right)
        {
            S.push(temp->Right);// 预留右指针在栈中
        }
        if(temp->Left)
        {
            temp=temp->Left;//进左子树
        }
        else//左子树为空
        {
            temp=S.top();
            S.pop();
        }
    }
    cout<<endl;
}

void Tree::PreOrder1() const
{
    TreeNode* temp=this->T;
    stack<TreeNode*>S;
    do
    {
        while(temp)
        {
            S.push(temp);
            cout<<temp->key<<" ";
            temp=temp->Left;
        }
        if(!S.empty())
        {
            temp=S.top();
            S.pop();
            temp=temp->Right;
        }
    }while(temp||!S.empty());
    cout<<endl;
}

void Tree::PostOrder() const
{
    stack<stkNode> S;
    TreeNode* temp=this->T;//遍历指针
    stkNode w;
    do
    {
        while(temp)
        {
            w.T=temp;
            w.tag=L;
            S.push(w);
            temp=temp->Left;
        }
        bool ok=1;//继续循环标记, 用于R
        while(ok&&!S.empty())
        {
            w=S.top();
            S.pop();
            temp=w.T;
            switch (w.tag)
            {
                case L:
                    w.tag=R;
                    S.push(w);
                    ok=0;
                    temp=temp->Right;
                    break;
                case R:
                    cout<<temp->key<<" ";
                    break;
            }
        }
    }while(!S.empty());// 继续遍历其他结点
    cout<<endl;
}