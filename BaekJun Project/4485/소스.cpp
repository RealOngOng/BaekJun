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

int dx[4] = {1,0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	int tc = 0;
	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;

		function<int(int, int)> ToIdx = [&](int x, int y) -> int
		{
			return x * n + y % n;
		};
		function<bool(int, int)> isOut = [&](int x, int y) -> bool
		{
			return (x < 0 || y < 0 || x >= n || y >= n);
		};
 
		vector<Line> V[125 * 125 + 1];
		vector<vector<int>> field(n, vector<int>(n));
		vector<int> dst(125 * 125 + 1, 0x3f3f3f3f);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> field[i][j];

		for(int i=0;i < n; i++)
			for(int j=0; j < n; j++)
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k], ny = j + dy[k];
					if (isOut(nx, ny)) continue;
					V[ToIdx(i, j)].push_back({ToIdx(nx, ny), field[nx][ny]});
				}

		priority_queue<Q, vector<Q>, cmp> pq;
		pq.push({0, field[0][0]});
		while (!pq.empty())
		{
			Q top = pq.top(); pq.pop();
			if (top.pos == n * n - 1)
			{
				cout << "Problem " << ++tc << ": "<< top.cost << "\n";
				break;
			}
			for (Line w : V[top.pos])
			{
				if (dst[w.to] > top.cost + w.cost)
				{
					dst[w.to] = top.cost; +w.cost;
					pq.push({w.to, top.cost + w.cost});
				}
			}
		}

	}
	return 0;
}