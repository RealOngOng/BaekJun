#include <bits/stdc++.h>

using namespace std;

struct Line
{
	int to, cost;
};
struct Q
{
	int pos, cost;
	bool visita, visitb;
	bool isDst() { return (visita && visitb); }
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

int dst[2][2][801];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dst, 0x3f3f3f3f, sizeof(dst));
	int n, m; cin >> n >> m;
	vector<Line> V[801];
	for (int i = 0; i < m; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		V[from].push_back({to, cost});
		V[to].push_back({from, cost});
	}
	int a, b; cin >> a >> b;

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({1, 0, (a == 1), (b == 1)});
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == n && top.isDst())
		{
			cout << top.cost;
			return 0;
		}
		for (Line w : V[top.pos])
		{
			if (dst[top.visita][top.visitb][w.to] > top.cost + w.cost)
			{
				dst[top.visita][top.visitb][w.to] = top.cost + w.cost;
				pq.push({w.to, top.cost + w.cost, 
						max(top.visita, (w.to == a)), max(top.visitb, (w.to == b))});
			}
		}
	}
	cout << "-1\n";
	return 0;
}