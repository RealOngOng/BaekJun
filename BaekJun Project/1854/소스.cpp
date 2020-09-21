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
vector<int> R[1001];

int main()
{
	for (int i = 0; i <= 1000; i++)
		dst[i] = 2 * 0x3f3f3f3f;

	int n, m, k; cin >> n >> m >> k;
	while (m--)
	{
		int a, b, c; cin >> a >> b >> c;
		V[a].push_back({b, c});
	}

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({1, 0});

	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();

		if (R[top.pos].size() < k)
			R[top.pos].push_back(top.cost);

		for (Line w : V[top.pos])
		{
			dst[w.to] = top.cost + w.cost;
			pq.push({ w.to, top.cost + w.cost });
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (R[i].size() < k) cout << "-1\n";
		else cout << R[i][k-1] << "\n";
	}
	return 0;
}