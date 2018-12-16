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

int n;
bool G[128][128] = { 0 };
int degree[128] = { 0 };
string str;

void DFS(char start)
{
	for (int i = 'A'; i <= 'z'; i++)
	{
		if (G[start][i])
		{
			G[start][i] = 0;
			G[i][start] = 0;
			degree[start]--;
			degree[i]--;
			DFS(i);
		}
	}
	str.push_back(start);//NB！！！
}

int main()
{
    cin >> n;
    char a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
		degree[a]++;
		degree[b]++;
    }
	char cnt = 0,start=0;
	for (char i = 'A'; i <= 'z'; i++)
	{
		if (degree[i] & 1)
			cnt++;
		if (degree[1]&&!start)
			start = i;
	}
	if (cnt > 2)
	{
		cout<<"No Solution"<<endl;
		return 0;
	}
	else if (cnt == 2)
	{
		for (char i = 'A'; i <= 'z'; i++)
		{
			if (degree[i] & 1)
			{
				DFS(i);
				break;
			}
		}
	}
	else if (cnt == 0)
	{
		DFS(start);
	}
	string out;
	int len = str.length();
	out.resize(len);
	for (int i = 0; i < len; i++)
	{
		out[i] = str[len - 1 - i];
	}
	cout << out << endl;
    return 0;
}
/*
6
AB
BE
EF
BF
BC
CD
*/