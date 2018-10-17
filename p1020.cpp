#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int equal(const int *arr,const int& Count, int p)
{
    for(int i=p;i<Count;i++)
    {
        if(arr[i]!=arr[p])
        {
            return i;
        }
    }
    return Count+1;
}

int Find(int *arr,const int &Count,const int& key)//return the first postion which element is less than key
{
    int x=0,y=Count-1;
    if(Count==1)
    {
        if(key>arr[0])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    while(x<y)
    {
        int m=(x+y)/2;
        if(key==arr[x])
        {
            return equal(arr,Count,x);
        }
        else if(key==arr[y])
        {
            return equal(arr,Count,y);
        }
        else if(key==arr[m])
        {
            return equal(arr,Count,m);
        }
        else if(key>arr[x])
        {
            return x;
        }
        else if(key<arr[y])
        {
            return y+1;
        }
        else if(x==m)
        {
            return m+1;
        }
        else if(key>arr[m])
        {
            y=m;
        }
        else if(key<arr[m])
        {
            x=m;
        }
    }
}

int main()
{
    vector<int> vec;
    int temp;
    do
    {
        scanf("%d",&temp);
        vec.push_back(temp);
    }while(getchar()!='\n');
    int n=vec.size();
    int *dp=new int[n];
    int *changes=new int[n];
    memset(changes,0,sizeof(int)*n);
    memset(dp,0,sizeof(int)*n);//dp[i]refers to the least
    int Count=1;
    dp[0]=vec[0];
    changes[0]=1;
    for(int i=1;i<n;i++)
    {
        int p=Find(dp,Count,vec[i]);
        dp[p]=vec[i];
        changes[p]++;
        if(p>=Count)
        {
            Count++;
        }
    }
    int max=0;
    for(int i=0;i<Count;i++)
    {
        if(changes[i]>max)
        {
            max=changes[i];
        }
    }
    cout<<Count<<' '<<max<<endl;
    delete []dp;
    delete []changes;
    return 0;
}
