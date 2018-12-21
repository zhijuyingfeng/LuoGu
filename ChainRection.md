#Chain Reaction
There are **n** beacons located at distinct positions on a number line. The i-th beacon has position **${a_i}$** and power level **${b_i}$**. When the i-th beacon is activated, it destroys all beacons to its left (direction of decreasing coordinates) within distance bi inclusive. The beacon itself is not destroyed however. Saitama will activate the beacons one at a time from right to left. If a beacon is destroyed, it cannot be activated.

Saitama wants Genos to add a beacon strictly to the right of all the existing beacons, with any position and any power level, such that the least possible number of beacons are destroyed. Note that Genos's placement of the beacon means it will be the first beacon activated. Help Genos by finding the minimum number of beacons that could be destroyed.

###Input
The first line of input contains a single integer n (1 ≤ n ≤ 100 000) — the initial number of beacons.

The i-th of next n lines contains two integers **${a_i}$** and **${b_i}$** (0 ≤ **${a_i}$** ≤ 1 000 000,1 ≤ **${b_i}$** ≤ 1 000 000)— the position and power level of the i-th beacon respectively. No two beacons will have the same position, so **${a_i}$** ≠ **${a_j}$** if i ≠ j.

###Output
Print a single integer — the minimum number of beacons that could be destroyed if exactly one beacon is added.

###Examples
input
```
4
1 9
3 1
6 1
7 4
```

output
```
1
```
<br></br>
input
```
7
1 1
2 1
3 1
4 1
5 1
6 1
7 1
```
output
```
3
```

###Note
For the first sample case, the minimum number of beacons destroyed is 1. One way to achieve this is to place a beacon at position 9 with power level 2.

For the second sample case, the minimum number of beacons destroyed is 3. One way to achieve this is to place a beacon at position 1337 with power level 42.


###思路
最开始时假设所有的灯塔全部被损毁，然后从左到右依次点亮灯塔。在这个过程中，点亮较右边的灯塔依然会毁灭范围内的左边灯塔。用dp数组表示点亮第i座灯塔后新增的可以点亮的灯塔数（如dp[i]为1表示点亮第i座灯塔后，亮的灯塔数目加1，这是因为左边没有灯塔在该灯塔的范围内；如为-1表示亮的灯塔数目减1，是因为左边有两座灯塔落在了该灯塔的范围内）。sum[i]表示$\sum_{k=0}^i dp[i]$。状态转移方程为dp[i]=$1-\sum d[k]$，其中k取满足下列条件的所有值：
$$
k<i\\
arr[k].pos>=arr[i].pos-arr[i].power
$$
n次处理结束后，sum[i]中的最大值即为同时亮的灯塔的数目的最大值，记为max，则n-max即为题目要求的结果。


###代码
```C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct beacon
{
	int pos, power;
};

bool cmp(const beacon&a, const beacon&b)
{
	return a.pos < b.pos;
}

int n;
int *dp;
int *sum;
beacon *arr;

int main()
{
	cin >> n;
	int max = 0;
	sum = new int[n];
	dp = new int[n];
	arr = new beacon[n];
	memset(dp, 0, sizeof(int)*n);
	memset(sum, 0, sizeof(int)*n);
	int L, R, mid;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].pos >> arr[i].power;
		dp[i] = 1;
		L = 0;
		R = i - 1;
		if(i&&arr[i].pos-arr[i].power>arr[i-1].pos)
		{
			dp[i] = 1;
			sum[i] = sum[i - 1] + 1;
			if (sum[i] > max)
			{
				max = sum[i];
			}
			continue;
		}
		else
		{
			while (L < R)//二分查找
			{
				mid = (L + R) >> 1;
				if (arr[i].pos - arr[i].power <= arr[mid].pos)
				{
					R = mid;
				}
				else
				{
					L = mid + 1;
				}
			}
		}
		if (i > 0)
		{
			dp[i] -= (sum[i - 1] - sum[L] + dp[L]);
			sum[i] = sum[i - 1] + dp[i];
		}
		else
		{
			dp[0] = 1;
			sum[0] = 1;
		}
		if (sum[i] > max)
		{
			max = sum[i];
		}
	}
	cout << n - max << endl;
	delete[]dp;
	delete[]sum;
	return 0;
}
```