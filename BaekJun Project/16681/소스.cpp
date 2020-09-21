#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX

typedef long long ll;

struct Line
{
	ll to, cost;
};
struct Q
{
	ll pos, cost;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

ll n, m, d, e;
vector<Line> V[100001];
ll h[100001];
vector<ll> updst(100001, INF);
vector<ll> downdst(100001, INF);

void dijkstra(bool rev)
{
	bitset<100001> visit;

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({((rev) ? 1 : n), 0});

	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();

		if (visit[top.pos]) continue;
		visit[top.pos] = true;

		if (rev && top.cost > downdst[top.pos]) continue;
		if (!rev && top.cost > updst[top.pos]) continue;

		for (Line w : V[top.pos])
		{
			if (h[top.pos] >= h[w.to]) continue;
			if (rev)
			{
				if (updst[w.to] > top.cost + w.cost)
				{
					updst[w.to] = top.cost + w.cost;
					pq.push({ w.to, top.cost + w.cost });
				}
			}
			else
			{
				if (downdst[w.to] > top.cost + w.cost)
				{
					downdst[w.to] = top.cost + w.cost;
					pq.push({ w.to, top.cost + w.cost });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	for (int i = 0; i < m; i++)
	{
		ll from, to, cost; cin >> from >> to >> cost;

		V[from].push_back({to, cost});
		V[to].push_back({from, cost});

	}

	dijkstra(true);
	dijkstra(false);

	ll ans = -INF;
	for (int i = 2; i < n; i++)
	{
		if (updst[i] == INF || downdst[i] == INF) continue;
		ll he = h[i] * e;
		ll dst = (updst[i] + downdst[i]) * d;
		ans = max(ans, he - dst);
	}

	if (ans == -INF) cout << "Impossible\n";
	else cout << ans;

	return 0;
}