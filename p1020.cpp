#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int>vec;
int n;
int cnt = 0;
int *dp;

void read()
{
	int temp;
	while(scanf("%d",&temp)!=EOF)
	{
		//scanf("%d", &temp);
		vec.push_back(temp);
	}
}

int main()
{
	read();
	n = vec.size();
	dp = new int[n];
	memset(dp, 0, sizeof(int)*n);
	int L, R, mid;
	dp[0] = vec[0];
	cnt = 1;
	for (int i = 1; i < n; i++)
	{
		L = 0;
		R = cnt - 1;
		if (vec[i] <= dp[R])
		{
			dp[cnt++] = vec[i];
			continue;
		}
		else if (vec[i] >= dp[L])
		{
			dp[0] = vec[i];
			continue;
		}
		while (L < R)
		{
			mid = (L + R) >> 1;
			if (mid == L)
			{
				if (vec[i] >= dp[R])
				{
					mid++;
					break;
				}
			}
			else if (vec[i] <= dp[mid])
			{
				L = mid;
			}
			else if (vec[i] > dp[mid])
			{
				R = mid;
			}
		}
		dp[mid] = vec[i];
	}
	cout << cnt << endl ;

	memset(dp, 0, sizeof(int)*n);
	dp[0] = vec[0];
	cnt = 1;

	for (int i = 1; i < n; i++)
	{
		L = 0;
		R = cnt - 1;
		if (vec[i] > dp[R])
		{
			dp[cnt++] = vec[i];
			continue;
		}
		else if (vec[i] <= dp[L])
		{
			dp[0] = vec[i];
			continue;
		}
		while (L < R)
		{
			mid = (L + R) >> 1;
			if (mid == L)
			{
				if (vec[i] <= dp[R])
				{
					mid++;
					break;
				}
			}
			else if (vec[i] > dp[mid])
			{
				L = mid;
			}
			else if (vec[i] <= dp[mid])
			{
				R = mid;
			}
		}
		dp[mid] = vec[i];
	}
	cout << cnt << endl;
	delete[]dp;
	return 0;
}
