#include <bits/stdc++.h>

using namespace std;

typedef struct Line
{
	long to, cost;
};
typedef struct Q
{
	long pos, cost;
	bool isFly = false;
};

vector<Line> V[50001];
long dst[2][50001];

struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(dst[0], dst[0] + 50001, LONG_MAX);
	fill(dst[1], dst[1] + 50001, LONG_MAX);
	long n, m, f, s, t; cin >> n >> m >> f >> s >> t;
	for (long i = 0; i < m; i++)
	{
		long from, to, cost; cin >> from >> to >> cost;
		V[from].push_back({ to, cost });
		V[to].push_back({ from, cost });
	}
	for (long i = 0; i < f; i++)
	{
		long from, to; cin >> from >> to;
		V[from].push_back({ to, 0 });
	}

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({ s, 0, false });
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == t)
		{
			cout << top.cost;
			break;
		}
		for (Line w : V[top.pos])
		{
			if (w.cost == 0)
			{
				if (top.isFly) continue;
				if (dst[top.isFly][w.to] > top.cost)
				{
					dst[top.isFly][w.to] = top.cost;
					pq.push({ w.to, top.cost, true });
				}
			}
			else
			{
				if (dst[top.isFly][w.to] > top.cost + w.cost)
				{
					dst[top.isFly][w.to] = top.cost + w.cost;
					pq.push({ w.to, top.cost + w.cost, false });
				}
			}
		}
	}

	return 0;
}