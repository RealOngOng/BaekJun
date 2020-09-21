#include <bits/stdc++.h>

using namespace std;

vector<int> V[1001];
int indegree[1001];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int cnt; cin >> cnt;
		vector<int> order(cnt);
		for (int j = 0; j < cnt; j++) cin >> order[j];

		for (int j = 0; j < cnt - 1; j++)
		{
			V[order[j]].push_back(order[j + 1]);
			indegree[order[j+1]]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> result;
	int cnt = 0;
	while (!q.empty())
	{
		int top = q.front(); q.pop();
		result.push_back(top);

		for (int w : V[top])
		{
			indegree[w]--;
			if (indegree[w] == 0) q.push(w);
		}
		cnt++;
	}

	if (cnt == n)
	{
		for (int w : result)
			cout << w << "\n";
	}
	else
		cout << "0";
	return 0;
}