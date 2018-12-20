#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge
{
    int to;
    int dist;
};

class cmp
{
public:
    bool operator()(const edge&a,const edge&b)
    {
        return a.dist>b.dist?1:0;
    }
};

int N,M;
vector<int>* arr;
int *dist;
priority_queue<edge,vector<edge>,cmp>H;
int *ways;

int main()
{
    scanf("%d %d",&N,&M);
    arr=new vector<int>[N+1];
    dist=new int[N+1];
    ways=new int[N+1];
    memset(dist,0xff,sizeof(int)*(N+1));
    memset(ways,0,sizeof(int)*(N+1));
    int x,y;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&x,&y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    H.push(edge{1,0});
    edge temp;
    ways[1]=1;
    while(!H.empty())
    {
        temp=H.top();
        H.pop();
        if(dist[temp.to]>=0)
            continue;
        dist[temp.to]=temp.dist;
        int size=arr[temp.to].size();
        int adjust;
        for(int i=0;i<size;i++)
        {
            adjust=arr[temp.to][i];
            if(dist[adjust]<0)
            {
                H.push(edge{adjust,dist[temp.to]+1});
            }
            if(temp.to>1&&dist[adjust]>=0&&dist[temp.to]==dist[adjust]+1)
            {
                ways[temp.to]+=ways[adjust];
                ways[temp.to]=ways[temp.to]%100003;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        cout<<ways[i]<<endl;
    }
    delete[]arr;
    delete[]ways;
    delete[]dist;
    return 0;
}
