#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    bool **arr=new bool*[n];
    int **dp=new int*[n];
    int *row1=new int[n];//表示第i行的上一个1出现的位置
    int *row2=new int[n];//表示第i行下一个1出现的位置
    int *column=new int[m];//表示第j列上一个1出现的位置
    memset(row1,-1,sizeof(int)*n);
    memset(row2,-1,sizeof(int)*n);
    memset(column,-1,sizeof(int)*m);
    for(int i=0;i<n;i++)
    {
        arr[i]=new bool[m];
        dp[i]=new int[m];
        memset(dp[i],0,sizeof(int)*m);
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int min1,min2,Max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j])
            {
                if(i>=1&&j>=1)
                {
                    if(row2[i]<=j)
                    {
                        int k=j+1;
                        while(k<m&&!arr[i][k])
                        {
                            k++;
                        }
                        row2[i]=k;
                    }
                    min1=min(j-row1[i],min(i-column[j],dp[i-1][j-1]+1));
                    min2=min(dp[i-1][j+1]+1,min(row2[i]-j,i-column[j]));
                    dp[i][j]=max(min1,min2);
                    row1[i]=j;
                    column[j]=i;
                    if(dp[i][j]>Max)
                        Max=dp[i][j];
                }
                else
                {
                    dp[i][j]=1;
                    row1[i]=j;
                    column[j]=i;
                    if(dp[i][j]>Max)
                        Max=dp[i][j];
                }
            }
        }
    }
    cout<<Max<<endl;
    for(int i=0;i<n;i++)
    {
        delete[]arr[i];
        delete[]dp[i];
    }
    delete[]dp;
    delete[]arr;
    delete[]row1;
    delete[]row2;
    delete[]column;
    return 0;
}

