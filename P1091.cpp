#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

const int maxn=100;
int n;
int arr[maxn],LIS[maxn],LDS[maxn];

void GetLIS()
{
    for(int i=0;i<n;i++)
    {
        LIS[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]&&LIS[j]+1>LIS[i])
            {
                LIS[i]=LIS[j]+1;
            }
        }
    }
}

void GetLDS()
{
    for(int i=n-1;i>=0;i--)
    {
        LDS[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j]&&LDS[j]+1>LDS[i])
            {
                LDS[i]=LDS[j]+1;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    GetLDS();
    GetLIS();
    int max=0,temp;
    for(int i=0;i<n;i++)
    {
        temp=LIS[i]+LDS[i]-1;
        if(temp>max)
        {
            max=temp;
        }
    }
    cout<<n-max<<endl;
    return 0;
}
