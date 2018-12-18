#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct edge
{
    int from;
    int to;
    int weight;
};

class cmp
{
public:
    bool operator()(const edge&a,const edge&b)
    {
        return a.weight>b.weight?1:0;
    }
};

int N,A,B;
const int maxn=101;
const int Infinity=0x7fffffff;
int dist[maxn];
priority_queue<edge,vector<edge>,cmp>H;
vector<int>arr[maxn];

int main()
{
    cin>>N>>A>>B;
    for(int i=0;i<maxn;i++)
    {
        dist[i]=Infinity;
    }
    int k,temp;
    for(int i=1;i<=N;i++)
    {
        cin>>k;
        arr[i].resize(k);
        for(int j=0;j<k;j++)
        {
            cin>>temp;
            arr[i][j]=temp;
        }
    }

    H.push(edge{0,A,0});
    dist[0]=0;
    edge top;
    while(!H.empty())
    {
        top=H.top();
        H.pop();
        if(dist[top.to]<Infinity)
        {
            continue;
        }
        temp=top.to;
        dist[temp]=top.weight;
        int size=arr[temp].size();
        for(int i=0;i<size;i++)
        {
            if(dist[arr[temp][i]]<Infinity)
                continue;
            H.push(edge{temp,arr[temp][i],dist[temp]+(i==0?0:1)});
        }
    }
    if(dist[B]==Infinity)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<dist[B]<<endl;
    }
    return 0;
}