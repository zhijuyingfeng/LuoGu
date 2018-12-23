#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	int N;
	int *A, *B;
	cin >> N;
	A = new int[N];
	B = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	priority_queue<int>H;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (H.size() < N)
			{
				H.push(A[i] + B[j]);
			}
			else
			{
				if(A[i]+B[j]>=H.top())
				{
					break;
				}
				else
				{
					H.pop();
					H.push(A[i] + B[j]);
				}
			}
		}
	}
	int *arr = new int[N];
	int i = 0;
	while (!H.empty())
	{
		arr[i++] = H.top();
		H.pop();
	}
	sort(arr, arr + N);
	for (i = 0; i < N - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[N - 1] << endl;
	delete[]arr;
	delete[]A;
	delete[]B;
	return 0;
}