#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Task
{
    int P,T;
};

bool cmp(const Task& a,const Task& b)
{
    return a.P>b.P?1:0;
}

int N,K;
Task* arr;
int *dp,*counts;

int main()
{
    cin>>N>>K;
    arr=new Task[K];
    dp=new int[N+2];
    counts=new int[N+1];
    memset(counts,0,sizeof(int)*(N+1));
    memset(dp,0,sizeof(int)*(N+2));
    for(int i=0;i<K;i++)
    {
        cin>>arr[i].P>>arr[i].T;
        counts[arr[i].P]++;
    }
    sort(arr,arr+K,cmp);
    int num=0;
    for(int i=N;i>0;i--)
    {
        if(counts[i])
        {
            for(int j=0;j<counts[i];j++)
            {
                if(dp[i+arr[num].T]>dp[i])
                {
                    dp[i]=dp[i+arr[num].T];
                }
                num++;
            }
        }
        else
        {
            dp[i]=dp[i+1]+1;
        }
    }
    cout<<dp[1]<<endl;
    delete[]counts;
    delete[]arr;
    delete[]dp;
    return 0;
}
