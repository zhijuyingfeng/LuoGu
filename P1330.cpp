#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> *arr;
bool *blocked;//标记节点是否被河蟹封锁
bool *visited;//标记节点是否被“短暂”访问过（每次循环其值会被清零）
bool *V;//标记节点是否被访问过

/*
核心思想是可由一个节点是否被封锁确定与之相邻的顶点是否应该被封锁
*/

int BFS()//返回需要封锁的节点数目
{
	queue<int> Q;
	int temp, cnt[2] = { 0 };
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (V[i]||arr[i].size()<=0)
			continue;
		cnt[0] = 0;cnt[1] = 0;
		for (int j = 0; j <= 1; j++)
		{
			memset(blocked, 0, sizeof(bool)*(N + 1));
			memset(visited, 0, sizeof(bool)*(N + 1));

			Q.push(i);
			blocked[i] = j;
			if (j)
				cnt[j]++;
			visited[i] = 1;
			while (!Q.empty())
			{
				temp = Q.front();
				Q.pop();
				visited[temp] = 1;
				V[temp] = 1;
				int size = arr[temp].size();
				for (int k = 0; k < size; k++)
				{
					if (visited[arr[temp][k]])
					{
						if (blocked[temp] == blocked[arr[temp][k]])
							return -1;
					}
					else
					{
						blocked[arr[temp][k]] = !blocked[temp];
						if (!blocked[temp])
						{
							cnt[j]++;
						}
						Q.push(arr[temp][k]);
					}
				}
			}
		}
		sum += (cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
	}
	return sum;
}

int main()
{
	cin >> N >> M;
	int A, B;
	arr = new vector<int>[N + 1];
	blocked = new bool[N + 1];
	visited = new bool[N + 1];
	V= new bool[N + 1];
	memset(blocked, 0, sizeof(bool)*(N + 1));
	memset(visited, 0, sizeof(bool)*(N + 1));
	memset(V, 0, sizeof(bool)*(N + 1));

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		arr[A].push_back(B);
		arr[B].push_back(A);
	}
	int cnt = BFS();
	if (cnt < 0)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << cnt << endl;
	}
	delete[]arr;
	delete[]visited;
	delete[]blocked;
	return 0;
}