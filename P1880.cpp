#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

const int maxn=200;
int dp[maxn][maxn]={0};
int n,arr[maxn],sum[maxn];

/*
因为题中为环形序列，所以将arr[0]~arr[n-1]复制到arr[n]~arr[2*n-1]以破环成链。
dp[i][j]表示合并从arr[i]到arr[j]（包括arr[i]与arr[j]）的石子为一堆的最大（最小）得分，
其状态转移方程为dp[i][j]=max{dp[i][k]+dp[k+1][j]+d(i,j))
其中0<=i<=k<j<n
d(i,j)表示从i到j的石子数量之和（包括i和j）
*/

void GetMax(int i,int j)
{
    if(j-i==1)
    {
        dp[i][j]=arr[i]+arr[j];
        return;
    }
    else if(i==j)
    {
        dp[i][j]=0;
        return;
    }
    int max=-1,temp;
    for(int k=i;k<j;k++)
    {
        if(dp[i][k]<0)
        {
            GetMax(i,k);
        }
        if(dp[k+1][j]<0)
        {
            GetMax(k+1,j);
        }
        if(i>0)
            temp=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
        else
            temp=dp[i][k]+dp[k+1][j]+sum[j];
        if(temp>max)
        {
            max=temp;
        }
    }
    dp[i][j]=max;
}

void GetMin(int i,int j)
{
    if(j-i==1)
    {
        dp[i][j]=arr[i]+arr[j];
        return;
    }
    else if(i==j)
    {
        dp[i][j]=0;
        return;
    }
    int min=0x7fffffff,temp;
    for(int k=i;k<j;k++)
    {
        if(dp[i][k]==0)//dp[i[[k]==0
        {
            GetMin(i,k);
        }
        if(dp[k+1][j]==0)//dp[k+1][j]==0
        {
            GetMin(k+1,j);
        }
        if(i>0)
            temp=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
        else
            temp=dp[i][k]+dp[k+1][j]+sum[j];
        if(temp<min)
        {
            min=temp;
        }
    }
    dp[i][j]=min;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[n+i]=arr[i];
    }
    sum[0]=arr[0];
    for(int i=1;i<(n<<1);i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
    int max=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            memset(dp[j],-1,sizeof(int)*maxn);
        }
        GetMax(i,i+n-1);
        if(dp[i][i+n-1]>max)
        {
            max=dp[i][i+n-1];
        }
    }
    int min=0x7fffffff;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            memset(dp[j],0,sizeof(int)*maxn);
        }
        GetMin(i,i+n-1);
        if(dp[i][i+n-1]<min)
        {
            min=dp[i][i+n-1];
        }
    }
    cout<<min<<endl<<max<<endl;
    return 0;
}
