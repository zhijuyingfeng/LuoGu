#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

struct Cnt
{
    int num,cnt;
    Cnt():num(0),cnt(0){}
};

const int Inf=1e6+1;
Cnt counts[Inf];
int *arr;
int n;

bool cmp(const Cnt&a,const Cnt&b)
{
    return a.num>b.num;
}

int main()
{
    cin>>n;
    arr=new int[n];
    int temp;
    for(int i=0;i<Inf;i++)
    {
        counts[i].num=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr[i]=temp;
        for(int j=1;j<=sqrt(temp);j++)
        {
            if(temp%j==0)
            {
                counts[j].cnt++;
                if(j*j!=temp)
                    counts[temp/j].cnt++;
            }
        }
    }
    vector<Cnt> vec;
    for(int i=0;i<Inf;i++)
    {
        if(counts[i].cnt>0)
            vec.push_back(counts[i]);
    }
    sort(vec.begin(),vec.end(),cmp);
    int size=vec.size();
    temp=0;
    for(int i=0;i<size;i++)
    {
        while(vec[i].cnt>temp)
        {
            cout<<vec[i].num<<endl;
            temp++;
        }
    }
    delete[]arr;
    return 0;
}

