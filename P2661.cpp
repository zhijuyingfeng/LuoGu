#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int  *arr;//�洢�����ڵ�����
int Min=0x7fffffff;
stack<int> S;
int *T;
bool *visited;
/*
һ����n����Ϣ����·�������Կ���һ��n���ڵ��ͼ��n���ߡ���һ�������������Ϊ1����ô���ͼ��Ȼ�л���
���ͼ��������������ɸ�����֦�ڵĻ���ɣ���Щ����֦�ڵĻ�֮��û����ϵ��
��Ȼ��ֻ�л��ϵĽڵ���п��ܽ��յ��Լ���������Ϣ����ˣ�������Ҫ����Щ�����ڻ���֦���޳���
Ȼ���ٱ����������ϵĶ��㣬�Ϳ��Եõ���̵�·����
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