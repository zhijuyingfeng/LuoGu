#Problems
In one very old text file there was written Great Wisdom. This Wisdom was so Great that nobody could decipher it, even Phong — the oldest among the inhabitants of Mainframe. But still he managed to get some information from there. For example, he managed to learn that User launches games for pleasure — and then terrible Game Cubes fall down on the city, bringing death to those modules, who cannot win the game…

For sure, as guard Bob appeared in Mainframe many modules stopped fearing Game Cubes. Because Bob (as he is alive yet) has never been defeated by User, and he always meddles with Game Cubes, because he is programmed to this.

However, unpleasant situations can happen, when a Game Cube falls down on Lost Angles. Because there lives a nasty virus — Hexadecimal, who is… mmm… very strange. And she likes to play very much. So, willy-nilly, Bob has to play with her first, and then with User.

This time Hexadecimal invented the following entertainment: Bob has to leap over binary search trees with n nodes. We should remind you that a binary search tree is a binary tree, each node has a distinct key, for each node the following is true: the left sub-tree of a node contains only nodes with keys less than the node's key, the right sub-tree of a node contains only nodes with keys greater than the node's key. All the keys are different positive integer numbers from 1 to n. Each node of such a tree can have up to two children, or have no children at all (in the case when a node is a leaf).

In Hexadecimal's game all the trees are different, but the height of each is not lower than h. In this problem «height» stands for the maximum amount of nodes on the way from the root to the remotest leaf, the root node and the leaf itself included. When Bob leaps over a tree, it disappears. Bob gets the access to a Cube, when there are no trees left. He knows how many trees he will have to leap over in the worst case. And you?

###Input
The input data contains two space-separated positive integer numbers n and h (n ≤ 35, h ≤ n).

###Output
Output one number — the answer to the problem. It is guaranteed that it does not exceed 9·1018.

##Examples
###Input

3 2
###Output

5
###Input

3 3
###Output

4

#思路
因题中所求为由n个节点组成的、高度大于等于h的搜索二叉树的数目。所谓高度，即为从叶节点到根的路径上的节点数目的最大值（包括叶节点和根节点自身）。

首先设置一个数组arr，arr[i]表示i个节点所能组成的树的数目，如arr[1]=1,arr[2]=2,arr[3]=5等。那么如何根据arr[1]~arr[n]推算arr[n+1]呢？
可以这样子思考：将一棵有n个节点的树分为左子树、右子树和根节点三部分，这样子就可以减小问题规模，又因为左右子树可能的数目之间没有关系，那么n个节点组成的树的数目就等于左子树可能的数目乘以右子树可能的数目。又将一棵有n个节点树分为上述三部分有n种方法（因为根节点固定占用一个节点，所以左子树节点数取[0,n-1]中的一个整数），然后就可以求解所有的arr[i]了（1$\leq$i$\leq$n）。参考代码如下：


```C++
arr[0]=1;
for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            arr[i]+=arr[j]*arr[i-j-1];
        }
    }
//事实上由于左右子树的对称性，该方法的时间复杂度还可以优化到当前的一半
```

因题中所求为高度大于等于h的树的数目，注意到树中只要有一个叶节点到根节点的路径长度大于等于h即可，从正面考虑比较复杂，我们可以从另一个方向思考：因为我们已经求得n个节点可以组成的不同的树的数目，因此我们只需要在此数目上减去高度小于h的树的数目即可。因此我们设置了一个二维数组dp，dp[i][j]表示由i个节点组成的、高度小于j的树的数目。显然，我们只需求得dp[n][h]即可。那么如何求到dp[n][h]呢？

依然将n个节点组成的树分为左子树、右子树和根节点三部分，因该树的高度小于h，故左右子树的高度小于h-1，又有n种分配方法，所以有 $$dp[n][h]=\sum\limits_{i=0}^{n-1}{(dp[i][h-1]*dp[n-i-1][h-1])}$$

这样子层层递推下去，什么时候才会停止呢？换句话说，边界条件是什么呢？首先如果h$\gt$n，也就是树的节点树比h要小，那么不管怎样，树的高度都不会超过h，因此此时dp[n][h]=arr[n]；另一方面，当树的节点数n大于高度为h-1的满二叉树的节点数的时候，无论怎么样安排，树的高度一定会大于等于h，即若n$\gt$2$^{h-1}$-1, dp[n][h]=0。

根据以上信息，我们就可以写出完整的代码了，参考代码如下：
```C++
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=36;
long long dp[maxn][maxn];//dp[n][h]表示由n个连续节点组成的、高度小于h的树的数目

long long pow(int x,int y)
{
    long long temp;
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else if(y&1)
    {
        temp=pow(x,y>>1);
        return temp*temp*x;
    }
    else
    {
        temp=pow(x,y>>1);
        return temp*temp;
    }
}

long long arr[maxn]={1};//arr[i]表示由n个节点可以组成的、不同的树的数目

void ComputeDp(int n,int h)
{
    if(n>=pow(2,h-1))
    {
        dp[n][h]=0;
        return;
    }
    if(h>n)
    {
        dp[n][h]=arr[n];
        return;
    }
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i][h-1]<0)
            ComputeDp(i,h-1);
        if(dp[n-i-1][h-1])
            ComputeDp(n-i-1,h-1);
        sum+=dp[i][h-1]*dp[n-i-1][h-1];
    }
    dp[n][h]=sum;
}

int main()
{
    for(int i=0;i<maxn;i++)
    {
        memset(dp[i], 0xff, sizeof(long long) * maxn);
        dp[0][i]=1;//这里将dp[0][i]初始化为1是为了方便计算
    }
    int n,h;
    cin>>n>>h;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            arr[i]+=arr[j]*arr[i-j-1];
        }
    }
    ComputeDp(n,h);
    cout<<arr[n]-dp[n][h]<<endl;
    return 0;
}
```
