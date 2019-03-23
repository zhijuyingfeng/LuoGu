#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

void power(unsigned long long arr[2][2],unsigned long long res[2][2],const int&n)
{
	if(1==n)
	{
		memcpy(res,arr,sizeof(unsigned long long)<<2);
		return;
	}
	else if(!n)
	{
		res[1][0]=0;
		return;
	}
	unsigned long long temp[2][2];
	power(arr,temp,n>>1);
	unsigned long long a=temp[0][0],b=temp[0][1],c=temp[1][0],d=temp[1][1];
	if(n&1)
	{
		res[0][0]=a*b+d*b;
		res[0][1]=a*a+b*(a+c+d);
		res[1][0]=b*c+d*d;
		res[1][1]=c*(a+b+d)+d*d;
	}
	else
	{
		res[0][0]=a*a+b*c;
		res[0][1]=b*(a+d);
		res[1][0]=c*(a+d);
		res[1][1]=b*c+d*d;
	}
}

unsigned long long Fibonacci(const int& n)
{
	unsigned long long arr[2][2]={{0,1},{1,1}};
	unsigned long long res[2][2];
	power(arr,res,n);
	return res[1][0];
}

int getDigits(const unsigned long long& n)
{
	if(!n)
		return 1;
	unsigned long long temp=n;
	int cnt=0;
	while(temp>0)
	{
		temp/=10;
		cnt++;
	}
	return cnt;
}

int main()
{
	unsigned long long ans;
	int digitsNum;
	for(int i=0;i<=60;i++)
	{
		ans=Fibonacci(i);
		digitsNum=getDigits(ans);
		printf("Fib(%d)=%llu %d digit",i,ans,digitsNum);
		if(digitsNum>1)
			printf("s");
		printf("\n");
	}
	return 0;
}
