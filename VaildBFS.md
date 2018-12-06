#Vaild BFS

The BFS algorithm is defined as follows.

* Consider an undirected graph with vertices numbered from 1 to n. Initialize q as a new queue containing only vertex 1, mark the vertex 1 as used.
* Extract a vertex v from the head of the queue q.
* Print the index of vertex v.
* Iterate in arbitrary order through all such vertices u that u is a neighbor of v and is not marked yet as used. Mark the vertex u as used and insert it into the tail of the queue q.
* If the queue is not empty, continue from step 2.
* Otherwise finish.
Since the order of choosing neighbors of each vertex can vary, it turns out that there may be multiple sequences which BFS can print.

In this problem you need to check whether a given sequence corresponds to some valid BFS traversal of the given tree starting from vertex 1. The tree is an undirected graph, such that there is exactly one simple path between any two vertices.

###Input
The first line contains a single integer n(1≤n≤$2⋅10^5$) which denotes the number of nodes in the tree.

The following n−1 lines describe the edges of the tree. Each of them contains two integers x and y(1≤x,y≤n) — the endpoints of the corresponding edge of the tree. It is guaranteed that the given graph is a tree.

The last line contains n distinct integers a1,a2,…,an(1≤ai≤n) — the sequence to check.

###Output
Print "Yes" (quotes for clarity) if the sequence corresponds to some valid BFS traversal of the given tree and "No" (quotes for clarity) otherwise.

###Examples
####input
```
4
1 2
1 3
2 4
1 2 3 4
```
####output

```
Yes
```
####input
```
4
1 2
1 3
2 4
1 2 4 3
```
####output
```
No
```

题目大意是给一个树，顶点从1到n，边由n-1行数据给出，然后再给一个1~n的序列，让我们写一个程序判断这个序列是否是合理的BFS遍历序列。

我的思路就是用队列来模拟BFS的过程，具体思路参见代码。

``` C++
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n;

struct Node
{
	vector<int> edges;
};

int main()
{
	cin >> n;
	Node* arr = new Node[n + 1];//记录每个节点相邻的节点
	int *seq = new int[n + 1];//存储输入的序列
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		arr[a].edges.push_back(b);
		arr[b].edges.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i+1];
	}

	bool* visited = new bool[n + 1];//记录该节点是否被访问过
	bool *appeared = new bool[n + 1];//记录节点是否入过队
	memset(visited, 0, sizeof(bool)*(n + 1));
	memset(appeared, 0, sizeof(bool)*(n + 1));

	queue<int>Q;
	Q.push(seq[1]);//将输入序列第一个数字入队
	int temp,size,p=1;//p表示当前入队的数字在序列中的位置
	appeared[seq[1]] = 1;
	bool ok = 1;//表示当前的BFS遍历是否合理

	while (!Q.empty()&&ok)
	{
		temp = Q.front();
		Q.pop();//弹出队首元素
		if (visited[temp])//如果当前数字已经被访问过，则不执行后面的语句
			continue;
		size = arr[temp].edges.size();//表示与当前数字相邻的节点数目
		if (temp != seq[1])//除序列第一个数字外，其他节点都有一个已经访问过的父节点，因此size要减1
			size--;
		visited[temp] = 1;//将当前数字标记为已访问

		for (int i=0; i < size; i++)//按照序列的顺序将数字入队
		{
			a = p + 1 + i;
			if (visited[seq[a]])
				continue;
			Q.push(seq[p + 1 + i]);
			appeared[seq[p + 1 + i]] = 1;
		}
		p += size;
		if (temp != seq[1])//因为下面的循环中包含了处理父节点的方法，因此减去的1要加回来
			size++;
		for (int i = 0; i < size; i++)//通过appeared数组检查刚刚入队的数字是否有误
		{
			a = arr[temp].edges[i];
			if (visited[a])
				continue;
			if (!appeared[a])//检查当前节点的儿子节点是否入队，如果不在队中，则该BFS遍历序列有误
			{
				cout << "No" << endl;
				ok = 0;
				break;
			}
		}
	}
	if (ok)
	{
		cout << "Yes" << endl;
	}
	delete[]seq;
	delete[]arr;
	delete[]appeared;
	delete[]visited;
	return 0;
}
```