#include <iostream>

using namespace std;

/*
Three steps:
1. move the smallest (n-1) plates from pillar A to pillar B with the assist of pillar C;
2. move the biggest plate from pillar A to pillar C;
3. move the (n-1) plates placed on pillar B to the pillar C with the assist of pillar A. 
*/
void Hanoi(char A,char B,char C, int n)
{
	if(n>1)
	{
		Hanoi(A,C,B,n-1);
		cout<<A<<" --> "<<C<<endl;
		Hanoi(B,A,C,n-1);
	}
	else
	{
		cout<<A<<" --> "<<C<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	Hanoi('A','B','C',4);
	return 0;
}