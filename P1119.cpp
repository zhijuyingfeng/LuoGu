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

const int maxn=200;
const int infinity=0x7fffffff;
int N,M;
int T[maxn]={0};
int Graph[maxn][maxn];
bool repaired[maxn]={0};
int dist[maxn][maxn];

void Floyd(const int &k)
{
    for(register int i=0;i<N;i++)
    {
        for(register int j=0;j<i;j++)
        {
            if(dist[i][k]>=0&&dist[k][j]>=0&&dist[i][j]>=0)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
            else if(dist[i][j]<0&&dist[i][k]>=0&&dist[k][j]>=0)
            {
                dist[i][j]=dist[i][k]+dist[k][j];
            }
            dist[j][i]=dist[i][j];
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>T[i];
    }
    for(int i=0;i<maxn;i++)
    {
        memset(Graph[i],0xff,sizeof(int)*maxn);
        memset(dist[i],0xff,sizeof(int)*maxn);
        dist[i][i]=0;
        Graph[i][i]=0;
    }
    int from,to,weight;
    for(int i=0;i<M;i++)
    {
        cin>>from>>to>>weight;
        Graph[from][to]=weight;
        Graph[to][from]=weight;
        dist[from][to]=weight;
        dist[to][from]=weight;
    }
    int Q;
    cin>>Q;
    int x,y,t;
    int tPos=0;
    for(int i=0;i<Q;i++)
    {
        cin>>x>>y>>t;
        while(tPos<N&&T[tPos]<=t)
        {
            repaired[tPos]=1;
            Floyd(tPos);
            tPos++;
        }
        if(!repaired[x]||!repaired[y])
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            cout<<dist[x][y]<<endl;
        }
    }
    return 0;
}
