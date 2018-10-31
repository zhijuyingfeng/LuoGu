#include <iostream>
#include <cstring>
using namespace std;


//https://www.zhihu.com/question/21923021/answer/281346746

/* P 为模式串，下标从 0 开始 */
void GetNext(char* P, int next[])
{
    int len=strlen(P);
    int i=0,j=-1;
    next[0]=-1;
    while(i<len-1)
    {
        if(j==-1||P[i]==P[j])
        {
            i++,j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int KMP(char* S,char *P, int *next)
{
    int P_len=strlen(P);
    int S_len=strlen(S);
    int j=0,i=0;
    while(i<S_len&&j<P_len)
    {
        if(j==-1||S[i]==P[j])
        {
            i++;j++;
        }
        else
        {
            j=next[j];
        }

    }
    if(j==P_len)
    {
        return i-j;
    }
    return -1;
}


int main()
{
    char P[]="ABCDABD";
    char S[]="BBC ABCDAB ABCDABCDABD";
    int P_len=strlen(P);
    int *next=new int[P_len];
    GetNext(P,next);
    cout<<KMP(S,P,next)<<endl;
    delete[]next;
    return 0;
}
