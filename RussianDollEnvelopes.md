##Russian Doll Envelopes
####题目描述
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note: Rotation is not allowed.

#####Input
The first line is a single integer n(1≤n≤300000), the number of envelopes.

The next n lines contains two integers seperated by space, the width w and height h of each envelope(1≤w,h≤1000000).

#####Output
Ouput the maximum number of envelopes you can Russian doll.

#####Example
input
```
4
5 4
6 4
6 7
2 3
```

output
```
3
```

####思路
先按照信封的高度（H）进行非升排序，然后再计算序列中W的最长下降序列。
注意当两个信封的高度相同时，应该把宽度（W）小的放在前面。因为这样子在访问后面的信封（即宽度较大的信封）时，可以将前面高度相同、宽度较小的信封覆盖掉，不会造成高度相同、宽度不同的两个信封“套”在一起。

AC代码如下:
```C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct env
{
	int H,W;
};

bool cmp(const env&a, const env&b)
{
	if (a.H == b.H)
		return a.W < b.W;//高度相同时，宽度较小的信封排在前面
	return a.H > b.H;
}

env*arr;
int n;
int *dp;//存储最长的宽度下降序列
//最终的序列不一定是最长下降序列，因为其中的元素会被后面的元素替换掉

int main()
{
	cin >> n;
	arr = new env[n];
	dp = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].W >> arr[i].H;
	}
	sort(arr, arr + n, cmp);
	int cnt = 1;
	dp[0] = arr[0].W;
	int L, R, mid;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].W < dp[cnt - 1])
		{
			dp[cnt++] = arr[i].W;
			continue;
		}
		else if (arr[i].W >= dp[0])
		{
			dp[0] = arr[i].W;
			continue;
		}
		L = 0;
		R = cnt - 1;
		while (L < R)//二分查找
		{
			mid = (L + R) >> 1;
			if (arr[i].W < dp[mid])
			{
				L = mid+1;
			}
			else
			{
				R = mid;
			}
		}
		dp[L] = arr[i].W;
	}
	cout << cnt << endl;
	delete[]arr;
	delete[]dp;
	return 0;
}
```