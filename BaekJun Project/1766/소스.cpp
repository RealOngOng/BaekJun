#include <bits/stdc++.h>

using namespace std;

vector<int> V[32001];
int indegree[32001];

struct cmp
{
	bool operator()(int a, int b) { return a > b; }
};

int main()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;

		V[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			pq.push(i);

	vector<int> order;
	while (!pq.empty())
	{
		int top = pq.top(); pq.pop();
		order.push_back(top);

		for (int w : V[top])
			if (--indegree[w] == 0) pq.push(w);
	}

	for (int w : order)
		cout << w << " ";

	return 0;
}