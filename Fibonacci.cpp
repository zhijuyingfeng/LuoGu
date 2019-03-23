#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

class Fib1
{
public:
	static void power(unsigned long long arr[2][2],unsigned long long res[2][2],const int&n)
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

	static unsigned long long Fibonacci(const int& n)
	{
		unsigned long long arr[2][2]={{0,1},{1,1}};
		unsigned long long res[2][2];
		power(arr,res,n);
		return res[1][0];
	}

	static int getDigits(const unsigned long long& n)
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

};

class Fib2
{
public:
	static unsigned long long Fibonacci(const int &n)
	{
		unsigned long long prev,curr;
		fibDriver(n,prev,curr);
		return curr;
	}

	//Compute the pair fib(n),fib(n-1)
	static void fibDriver(const int&n,unsigned long long &prev,unsigned long long& curr)
	{
		if(1==n)
		{
			prev=0;curr=1;
			return;
		}
		else if(!n)
		{
			prev=1;
			curr=0;
			return;
		}
		unsigned long long p,c,next,m=n>>1;
		fibDriver(m,p,c);//fib(m-1),fib(m)
		prev=p*p+c*c;//fib(2*m-1)
		curr=c*(c+(p<<1));//fib(2*m)
		if(n&1)
		{
			next=prev+curr;//fib(2*m+1)
			prev=curr;curr=next;
		}
	}
};

int main()
{
	unsigned long long ans;
	int digitsNum;
	for(int i=0;i<=60;i++)
	{
		ans=Fib2::Fibonacci(i);
		digitsNum=Fib1::getDigits(ans);
		printf("Fib(%d)=%llu %d digit",i,ans,digitsNum);
		if(digitsNum>1)
			printf("s");
		printf("\n");
	}
	return 0;
}
