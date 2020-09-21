#include <bits/stdc++.h>

using namespace std;

struct Line
{
	int to, cost;
};
struct Q
{
	int pos, cost;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

vector<Line> V[1001];
int route[1001];

void dijkstra(int s)
{
	vector<int> dst(1001, 0x3f3f3f3f);

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({ s, 0 });

	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		for (Line w : V[top.pos])
		{
			if (dst[w.to] > top.cost + w.cost)
			{
				dst[w.to] = top.cost + w.cost;
				route[w.to] = top.pos;
				pq.push({ w.to, top.cost + w.cost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		V[from].push_back({ to, cost });
		V[to].push_back({ from, cost });
	}

	dijkstra(1);

	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++)
		cout << route[i] << " " << i << "\n";

	return 0;
}