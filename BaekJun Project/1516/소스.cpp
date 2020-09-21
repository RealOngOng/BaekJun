#include <bits/stdc++.h>

using namespace std;

vector<int> V[501];
int t[501];
int result[501];
int indegree[501];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		
		int top = 0;
		while (top != -1)
		{
			cin >> top;
			if (top == -1) break;

			V[top].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
		{
			q.push(i);
			result[i] = t[i];
		}

	vector<int> order;
	while (!q.empty())
	{
		int top = q.front(); q.pop();
		order.push_back(top);

		for (int w : V[top])
		{
			result[w] = max(result[w], result[top] + t[w]);
			if (--indegree[w] == 0) q.push(w);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	return 0;
}