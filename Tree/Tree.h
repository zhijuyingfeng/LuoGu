#ifndef CLIONAPPLICATION2_TREE_H
#define CLIONAPPLICATION2_TREE_H

struct TreeNode
{
    int key;
    TreeNode *Left,*Right;
    TreeNode():key(0),Left(NULL),Right(NULL){}
    TreeNode(int k):key(k),Left(NULL),Right(NULL){}
};

enum Tag{L,R};

struct stkNode
{
    TreeNode* T;// 树结点指针
    Tag tag;// 退栈标记
    stkNode():T(NULL),tag(L){}// 构造函数
    /*
     * tag = L, 表示从左子树退回还要遍历右子树;
     * tag = R,表示从右子树退回要访问根结点。
     *
     */
};

class Tree
{
public:
    Tree();
    ~Tree();
    void LDR();
    void DLR();
    void LRD();
    void SetRoot(int k);
    void AddNode(int k);
    void DeleteNode(int k);
    TreeNode* FindNode(int k);
    int FindMax();
    void LevelTraversal();
    void PreOrder2()const;//First order traversal without recursion
    void InOrder()const;//sequential traversal without recursion
    void PreOrder1()const;
    void PostOrder()const;
private:
    TreeNode* FindMaxDriver(TreeNode* T);
    TreeNode* AddNodeDriver(int k, TreeNode* T);
    TreeNode* DeleteNodeDriver(int k, TreeNode* T);
    void DLRDriver(const TreeNode *T);//First order traversal
    void LDRDriver(const TreeNode * T);//sequential traversal
    void LRDDriver(const TreeNode * T);//post order traversal
    TreeNode* FindNodeDriver(int k,TreeNode* T);
    TreeNode* T;
    void MakeEmpty(TreeNode* T);

};


#endif //CLIONAPPLICATION2_TREE_H

