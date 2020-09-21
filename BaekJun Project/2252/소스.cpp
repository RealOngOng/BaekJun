#include <bits/stdc++.h>

using namespace std;

vector<int> V[32001];
int indegree[32001];

int main()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		V[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> order;
	while (!q.empty())
	{
		int top = q.front(); q.pop();
		order.push_back(top);

		for (int w : V[top])
			if (--indegree[w] == 0) q.push(w);
	}

	for (int w : order)
		cout << w << " ";
	return 0;
}