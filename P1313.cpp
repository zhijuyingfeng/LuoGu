#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int K=1001;
const int con=10007;
int dp[K][K]={0};

int com(const int& n,const int &i)
{
    if(dp[n][i])
        return dp[n][i];
    if(!i&&n==i)
    {
        dp[n][i]=1;
        return 1;
    }
    if(n==i+1||i==1)
    {
        dp[n][i]=n;
        return n;
    }
    dp[n-1][i-1]=com(n-1,i-1)%con;
    dp[n-1][i]=com(n-1,i)%con;
    dp[n][i]=(dp[n-1][i]+dp[n-1][i-1])%con;
    return dp[n][i];
}

int power(const int& x,const int& y)
{
    if(!y)
        return 1;
    if(y==1)
        return x%con;
    long long temp=power(x,y>>1);
    if(y&1)
        return (temp*temp*x)%con ;
    else
        return (temp*temp)%con;
}

int main()
{
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    long long ans=1;
    ans=(com(k,m)*power(b,m))%con;
    ans=(ans*power(a,n))%con;
    cout<<ans<<endl;
    return 0;
}

