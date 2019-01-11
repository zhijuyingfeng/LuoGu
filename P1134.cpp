#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int  foo(const int &x)
{
    if(x<=11)
    {
        int ans=1;
        for(int i=1;i<=x;i++)
        {
            ans*=i;
        }
        return ans%10;
    }
    int temp=x;
    int cnt=0;
    vector<int> vec;
    while(temp>10)
    {
        for(int i=2;i<=temp%10;i++)
        {
            if(i!=5)
            {
                vec.push_back(temp/10*10+i);
            }
        }
        cnt+=(temp/5)%4;
        temp/=5;
    }
    cnt=(cnt+temp/5)%4;
    for(int i=2;i<=temp;i++)
    {
        if(i!=5)
        vec.push_back(i);
    }
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    {
        if(cnt<=0)
            break;
        if(!(*it&1))
        {
            *it=(*it>>1);
            cnt--;
        }
    }
    int ans=6;
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    {
        ans=(ans*(*it))%10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<foo(n)<<endl;
    return 0;
}

