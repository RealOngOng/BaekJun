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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dst[100 * 100 + 1];
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		if (q1.cost != q2.cost) return q1.cost > q2.cost;
		return q1.pos < q2.pos;
	}
};

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));
	int n, m; cin >> n >> m;
	vector<string> arr(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	function<int(int, int)> ToIdx = [&](int x, int y) -> int
	{
		return x * n + y % n;
	};
	function<bool(int, int)> isOut = [&](int x, int y) -> bool
	{
		return (x < 0 || y < 0 || x >= m || y >= n);
	};

	vector<Line> V[100 * 100 + 1];

	for(int i=0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (isOut(nx, ny)) continue;
				V[ToIdx(i, j)].push_back({ ToIdx(nx, ny), (arr[nx][ny] - '0') });
			}
		}

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({0, 0});

	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == n * m - 1)
		{
			cout << top.cost;
			break;
		}
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