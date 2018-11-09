#include <iostream>
#include <cstring>
using namespace std;

const int maxn=800;
char InOrder[maxn];
char PreOrder[maxn];
int *weight;//count the weight of vertex
int No=0;//Number in the PreOrder sequence

int Recur(int L,int R)
{
    int i=L;
    for(;i<=R;i++)
    {
        if(InOrder[i]==PreOrder[No])
            break;
    }
    int temp=No;
    int temp1,temp2;
    No++;
    if(i!=L)//If it has left child, go left
        temp1=Recur(L,i-1);
    else
        temp1=0;
    if(i!=R)//If it has right child, go right
        temp2=Recur(i+1,R);
    else
        temp2=0;
    if(i==L&&i==R)//leaf vertex
    {
        weight[temp]=1;
        return 1;
    }
    else
    {
        weight[temp]=temp1+temp2;
        return temp1+temp2;
    }
}

int main()
{
    cin>>PreOrder>>InOrder;
    int len=strlen(InOrder);
    weight=new int[len];
    Recur(0,len-1);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<weight[i];j++)
        {
            cout<<PreOrder[i];
        }
        cout<<endl;
    }
    delete[]weight;
    return 0;
}