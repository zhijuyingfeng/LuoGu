#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> M >> N;
    int *A = new int[M];
    int *u = new int[N];
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> u[i];
    }
    priority_queue<int>L;
    priority_queue<int, vector<int>, greater<int> >R;
    int j = 0;
    for (int i = 0; i < M; i++)
    {
        if (L.size() < j + 1)
        {
            if (R.empty()||A[i] <= R.top())
            {
                L.push(A[i]);
            }
            else
            {
                R.push(A[i]);
                L.push(R.top());
                R.pop();
                L.push(R.top());
                R.pop();
            }
        }
        else 
        {
            if (A[i] <= L.top())
            {
                R.push(L.top());
                L.pop();
                L.push(A[i]);
            }
            else
            {
                R.push(A[i]);
            }
        }
        while (i == u[j] - 1)
        {
            cout << L.top() << endl;
            j++;
            if (!R.empty())
            {
                L.push(R.top());
                R.pop();
            }
        }
    }
    delete[]A;
    delete[]u;
    return 0;
}