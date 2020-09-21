#include <bits/stdc++.h>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	vector<int> V[10];
	vector<int> indegree(10, 0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if (c == '<')
		{
			V[i + 1].push_back(i);
			indegree[i]++;
		}
		else
		{
			V[i].push_back(i+1);
			indegree[i+1]++;
		}
	}

	priority_queue<int, vector<int>, cmp> maxpq;
	priority_queue<int> minpq;

	for(int i=0; i <= n; i++)
		if (indegree[i] == 0)
		{
			maxpq.push(i);
			minpq.push(i);
		}

	vector<int> maxorder(11), minorder(11);

	vector<int> maxindegree(indegree);
	vector<int> minindegree(indegree);

	int idx = 9;
	while (!maxpq.empty())
	{
		int top = maxpq.top(); maxpq.pop();

		maxorder[top] = idx--;
		for (int w : V[top])
			if (--maxindegree[w] == 0) maxpq.push(w);
	}
	
	idx = n;
	while (!minpq.empty())
	{
		int top = minpq.top(); minpq.pop();

		minorder[top] = idx--;
		for (int w : V[top])
			if (--minindegree[w] == 0) minpq.push(w);
	}

	for (int i = 0; i <= n; i++)
		cout << maxorder[i];
	cout << "\n";
	for (int i = 0; i <= n; i++)
		cout << minorder[i];

	return 0;
}