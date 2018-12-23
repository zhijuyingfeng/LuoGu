#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct task
{
	int No, start, exe, priority;
};

class cmp
{
public:
	bool operator()(const task&a, const task&b)
	{
		if (a.priority == b.priority)
			return a.start > b.start;
		return a.priority < b.priority;
	}
};

int main()
{
	priority_queue<task, vector<task>, cmp>H;
	vector<task>vec;
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
	//for(int i=0;i<8;i++)
	{
		//scanf("%d%d%d%d", &a, &b, &c, &d);
		vec.push_back(task{ a,b,c,d });
	}
	int n = vec.size();
	int time = vec[0].start;
	task temp=vec[0];
	int j = 1;
	for (int i = 0; i < n; )
	{
		if (j<n&&vec[j].start < time + temp.exe)
		{
			if (vec[j].priority > temp.priority)
			{
				temp.exe -= vec[j].start - time;
				H.push(temp);
				time = vec[j].start;
				temp = vec[j];
				j++;
			}
			else
			{
				H.push(vec[j]);
				j++;
			}
		}
		else if ((j<n&&vec[j].start>=time + temp.exe)||j==n)
		{
			cout << temp.No << " " << temp.exe + time << endl;
			time += temp.exe;
			i++;
			if (!H.empty())
			{
				temp = H.top();
				H.pop();
			}
			else if(j<n)
			{
				temp = vec[j];
				time = vec[j].start;
				j++;
			}
		}
	}
	return 0;
}