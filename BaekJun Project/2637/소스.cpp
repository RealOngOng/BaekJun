#include <bits/stdc++.h>

using namespace std;

struct Data
{
	int to, cnt;
};

vector<Data> V[101];
int indegree[101];
int arr[101][101];

int main()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b, c; cin >> a >> b >> c;
		V[b].push_back({a, c});
		indegree[a]++;
	}

	queue<int> q;
	vector<int> def;
	for(int i=1; i <= n; i++)
		if (indegree[i] == 0)
		{
			def.push_back(i);
			arr[i][i] = 1;
			q.push(i);
		}
	
	while (!q.empty())
	{
		int top = q.front(); q.pop();

		for (Data w : V[top])
		{
			for (int i = 1; i <= n; i++)
				arr[w.to][i] += w.cnt * arr[top][i];

			if (--indegree[w.to] == 0)
				q.push(w.to);
		}
	}

	for (int w : def)
		cout << w << " " << arr[n][w] << "\n";
	return 0;
}