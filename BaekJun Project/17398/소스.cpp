#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int p[100001];
ll pcnt[100001];

int find(int x)
{
	if (p[x] == 0) return x;
	else
		return p[x] = find(p[x]);
}

bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a;
	pcnt[a] += pcnt[b];
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(pcnt, pcnt + 100001, 1LL);

	int n, m, q; cin >> n >> m >> q;
	
	vector<pi> query;
	vector<int> order;
	bitset<100001> visit;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		query.push_back({a, b});
	}
	for (int i = 0; i < q; i++)
	{
		int a; cin >> a;
		a--;
		order.push_back(a);
		visit[a] = true;
	}
	for (int i = 0; i < m; i++)
	{
		if (visit[i]) continue;
		merge(query[i].first, query[i].second);
	}

	ll ans = 0;
	for (pi p : query)
	{
		ll a = pcnt[find(p.first)];
		ll b = pcnt[find(p.second)];
		if (!merge(p.first, p.second)) continue;

		ans += a * b;
	}
	cout << ans;

	return 0;
}