#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int  *arr;//存储各个节点的入度
int Min=0x7fffffff;
stack<int> S;
int *T;
bool *visited;
/*
一共有n条信息传递路径，可以看成一个n个节点的图有n条边。且一个顶点出度至多为1，那么这个图必然有环。
这个图可以想象成由若干个带有枝节的环组成，这些带有枝节的环之间没有联系。
显然，只有环上的节点才有可能接收到自己的生日信息，因此，首先需要把这些依附于环的枝节剔除。
然后再遍历各个环上的顶点，就可以得到最短的路径。
*/
int main()
{
	cin >> n;
	arr = new int[n+1];
	T = new int[n + 1];
	visited = new bool[n + 1];
	memset(arr, 0, sizeof(int)*(n + 1));
	memset(visited, 0, sizeof(bool)*(n + 1));
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		T[i] = temp;
		arr[temp]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			S.push(i);
		}
	}
	while (!S.empty())
	{
		temp = S.top();
		S.pop();
		while (arr[temp] <= 0)
		{
			visited[temp] = 1;
			temp = T[temp];
			arr[temp]--;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		temp = T[i];
		int cnt = 0;
		while (!visited[temp])
		{
			visited[temp] = 1;
			cnt++;
			temp = T[temp];
		}
		if (cnt < Min)
		{
			Min = cnt;
		}
	}
	cout << Min+1 << endl;
	delete[]visited;
	delete[]T;
	delete[]arr;
	return 0;
}