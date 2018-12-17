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
    bool operator()(const edge&a, const edge& b)
    {
        return a.weight > b.weight ? 1 : 0;
    }
};

int n;
priority_queue<edge,vector<edge>,cmp> H;
int UFS[100];

int Find(const  int &x)
{
    return x == UFS[x] ? x : UFS[x] = Find(UFS[x]);
}

int main()
{
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        UFS[i] = i;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (j < i)
            {
                H.push(edge{ i, j, temp });
            }
        }
    }
    edge Temp;
    int sum = 0;
    int a, b;
    int cnt = 0;
    while (!H.empty())
    {
        Temp = H.top();
        H.pop();
        a = Temp.from;
        b = Temp.to;
        int x=Find(a);
        int y=Find(b);
        if (x != y)
        {
            sum += Temp.weight;
            UFS[x] = y;
            cnt++;
        }
        if (cnt == n-1)
        {
        	break;
        }
    }
    cout << sum << endl;
    return 0;
}