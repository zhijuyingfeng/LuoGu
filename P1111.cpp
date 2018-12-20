#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct  edge
{
    int from;
    int to;
    int time;
};

bool cmp(const edge&a,const edge&b)
{
    return a.time<b.time;
}

int *UFS;
int N,M;
int ans=-1;
edge*arr;

int Find(const int &x)
{
    return x==UFS[x]?x:UFS[x]=Find(UFS[x]);
}

int main()
{
    cin>>N>>M;
    UFS=new int[N+1];
    arr=new edge[M];
    for(int i=0;i<=N;i++)
    {
        UFS[i]=i;
    }
    for(int i=0;i<M;i++)
    {
        cin>>arr[i].from>>arr[i].to>>arr[i].time;
    }
    sort(arr,arr+M,cmp);
    int x,y;
    for(int i=0;i<M;i++)
    {
        x=Find(arr[i].from);
        y=Find(arr[i].to);
        if(x!=y)
        {
            ans=arr[i].time;
            UFS[x]=y;
        }
    }
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        if(UFS[i]==i)
            cnt++;
    }
    if(cnt>1)
        ans=-1;
    cout<<ans<<endl;
    delete[]arr;
    delete[]UFS;
    return 0;
}
