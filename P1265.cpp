#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct vertex
{
	long long x, y;
	int No;
};

struct edge
{
	int from;
	int to;
	double weight;
};

double CalDist(const vertex&a, const vertex&b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int n;
vertex* arr;
double *dist;
bool *visited;

int main()
{
	cin >> n;
	arr = new vertex[n];
	dist = new double[n];
	visited = new bool[n];
	memset(visited, 0, sizeof(bool)*n);
	for (int i = 0; i < n; i++)
	{
		dist[i] = i;
		dist[i] = 4e7;
		cin >> arr[i].x >> arr[i].y;
		arr[i].No = i;
	}

	int temp = 0;
	double sum = 0,min;
	int cnt = 0,pos;
	double d;

	for(int i=0;i<n-1;i++)
	{
		visited[temp] = 1;
		min = 4e7;
		for (int j = 0; j < n; j++)
		{
			if (visited[j])
			{
				dist[j] = 4e7;
				continue;
			}
			d = CalDist(arr[temp], arr[j]);
			if (dist[j] > d)
			{
				dist[j] = d;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (dist[j] < min)
			{
				min = dist[j];
				pos = j;
			}
		}
		temp = pos;
		sum += min;
	}
	
	printf("%.2f\n", sum);
	delete[]visited;
	delete[]arr;
	delete[]dist;
    return 0;
}