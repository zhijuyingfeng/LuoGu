#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int  *arr;//存储各个节点的入边
stack<int> S;
int *T;
bool *visited;
bool *Visited;
int *dist;

int main()
{
	cin >> n;
	arr = new int[n + 1];
	T = new int[n + 1];
	visited = new bool[n + 1];
	Visited = new bool[n + 1];
	dist = new int[n + 1];
	memset(dist, 0xff, sizeof(int)*(n + 1));
	memset(arr, 0, sizeof(int)*(n + 1));
	memset(visited, 0, sizeof(bool)*(n + 1));
	memset(Visited, 0, sizeof(bool)*(n + 1));
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
		if (visited[i]||Visited[i])
			continue;
		Visited[i] = 1;
		temp = T[i];
		//if (temp == i)
		//{
		//	Visited[i] = 1;
		//	dist[i] = 1;
		//	continue;
		//}
		S.push(i);
		int cnt = 1;
		while (!Visited[temp])
		{
			Visited[temp] = 1;
			cnt++;
			S.push(temp);
			temp = T[temp];
		}
		while (!S.empty())
		{
			temp = S.top();
			dist[temp] = cnt;
			S.pop();
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i]<0)
		{
			temp = i;
			while (dist[temp] < 0)
			{
				S.push(temp);
				temp = T[temp];
			}
			int value = dist[temp];
			while (!S.empty())
			{
				temp = S.top();
				dist[temp] = ++value;
				S.pop();
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << endl;
	}
	delete[]visited;
	delete[]T;
	delete[]arr;
	delete[]Visited;
	delete[]dist;
	return 0;
}