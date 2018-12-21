#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct stick
{
	int L, W;
};

bool cmp(const stick&a, const stick&b)
{
	if (a.L == b.L)
		return a.W > b.W;
	return a.L > b.L;
}

stick* sticks;
int n;
int *dp;

/*dilworth定理*/

int main()
{
	cin >> n;
	sticks = new stick[n];
	dp = new int[n];
	memset(dp, 0, sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		cin >> sticks[i].L >> sticks[i].W;
	}
	sort(sticks, sticks + n, cmp);
	int cnt = 1;
	dp[0] = sticks[0].W;
	int L, R, mid;
	for (int i = 1; i < n; i++)
	{
		if (sticks[i].W > dp[cnt-1])
		{
			dp[cnt++] = sticks[i].W;
			continue;
		}
		else if (sticks[i].W < dp[0])
		{
			dp[0] = sticks[i].W;
			continue;
		}
		L = 0;
		R = cnt - 1;
		while (L < R)
		{
			mid = (L + R) >> 1;
			if (sticks[i].W > dp[mid])
			{
				L = mid+1;
			}
			else
			{
				R = mid;
			}
		}
		dp[L] = sticks[i].W;
	}
	cout << cnt << endl;
	delete[]sticks;
	delete[]dp;
	return 0;
}