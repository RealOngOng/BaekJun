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

typedef pair<int, int> pi;

int main()
{
	while (true)
	{
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;
		int start, end; cin >> start >> end;

		vector<Line> V[501];

		for (int i = 0; i < m; i++)
		{
			int from, to, cost; cin >> from >> to >> cost;
			V[from].push_back({to, cost});
		}

		vector<Line> trace[501];
		function<int()> dijkstra = [&]() -> int
		{
			vector<int> dst(501, 0x3f3f3f3f);

			priority_queue<Q, vector<Q>, cmp> pq;
			pq.push({start, 0});
			dst[start] = 0;

			while (!pq.empty())
			{
				Q top = pq.top(); pq.pop();
				for (Line w : V[top.pos])
				{
					if (w.cost == -1) continue;
					if (dst[w.to] > top.cost + w.cost)
					{
						dst[w.to] = top.cost + w.cost;
						pq.push({w.to, top.cost + w.cost});

						trace[w.to].clear();
						trace[w.to].push_back({top.pos, dst[w.to]});
					}
					if(dst[w.to] == top.cost + w.cost)
						trace[w.to].push_back({ top.pos, dst[w.to] });
				}
			}

			return dst[end];
		};

		dijkstra();

		queue<int> q;
		q.push(end);
		while (!q.empty())
		{
			int top = q.front(); q.pop();
			for (Line& w : trace[top])
			{
				for (Line& l : V[w.to])
					if (l.to == top)
						l.cost = -1;

				q.push(w.to);
			}
		}
		
		int ans = dijkstra();
		if (ans == 0x3f3f3f3f) cout << "-1\n";
		else cout << ans << "\n";

	}
	return 0;
}