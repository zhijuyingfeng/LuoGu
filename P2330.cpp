#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct edge
{
	int from;
	int to;
	int weight;
};

class cmp
{
public:
	bool operator()(const edge&a, const edge& b)
	{
		return a.weight > b.weight ? 1 : 0;
	}
};

int n,m;
priority_queue<edge,vector<edge>,cmp> H;
int *UFS;

int Find(const  int &x)
{
	return x == UFS[x] ? x : UFS[x] = Find(UFS[x]);
}

int main()
{
    cin >> n>>m;
	UFS = new int[n+1];
	int u, v, c;
	for (int i = 0; i < n + 1;i++)
	{
		UFS[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> c;
		H.push(edge{ u,v,c });
	}
	edge temp;
	int max = 0;
	int a, b;
	int cnt = 0;
	while (!H.empty())
	{
		temp = H.top();
		H.pop();
		a = Find(temp.from);
		b = Find(temp.to);
		if (a!=b)
		{
			if (temp.weight > max)
				max = temp.weight;
			UFS[a] = b;
		}
		if (cnt == n-1)
		{
			break;
		}
	}
	cout <<n-1<<" "<< max << endl;
	delete[]UFS;
    return 0;
}