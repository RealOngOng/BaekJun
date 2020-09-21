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

int dst[1001];
vector<Line> V[1001];

int dijikstra(int start, int end)
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));
	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({start, 0});
	
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == end)
			return top.cost;

		for (Line w : V[top.pos])
		{
			if (dst[w.to] > top.cost + w.cost)
			{
				dst[w.to] = top.cost + w.cost;
				pq.push({w.to, top.cost + w.cost });
			}
		}
	}

	return 0;
}

int main()
{
	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		V[from].push_back({to, cost});
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int a = dijikstra(i, x), b = dijikstra(x, i);
		ans = max(ans, a + b);
	}

	cout << ans;
	return 0;
}