#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;

struct coe
{
	int A, B, C;
};

int cal(const coe& COE, const int &x)
{
	int sum = 0;
	sum += COE.A*x*x + COE.B*x + COE.C;
	return sum;
}

int main()
{
	int n, m;
	cin >> n >> m;
	coe* coes = new coe[n];
	for (int i = 0; i < n; i++)
	{
		cin >> coes[i].A >> coes[i].B >> coes[i].C;
	}
	priority_queue<int>Q;
	int *pos = new int[m];
	memset(pos, 0, sizeof(int)*n);
	bool ok = 1;
	for (int i = 1; i < 10000&&ok; i++)
	{
		ok = 0;
		for (int j = 0; j < n; j++)
		{
			if (Q.size() < m)
			{
				Q.push(cal(coes[j], i));
				ok = 1;
			}
			else
			{
				int temp = cal(coes[j], i);
				if (temp < Q.top())
				{
					Q.push(temp);
					Q.pop();
					ok = 1;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		pos[i] = Q.top();
		Q.pop();
	}
	for (int i = 0; i < m - 1; i++)
	{
		cout << pos[m - 1 - i] << " ";
	}
	cout << pos[0] << endl;
	delete[]pos;
	delete[]coes;
	return 0;
}