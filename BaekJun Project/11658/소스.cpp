#include <bits/stdc++.h>

using namespace std;

struct Fenwick2D
{
	int n, m;
	vector<vector<int>> tree;
	Fenwick2D(vector<vector<int>>& vec)
	{
		Init(vec);
	}

	void Init(vector<vector<int>>& vec)
	{
		n = vec.size() + 1;
		m = vec[0].size() + 1;
		tree.resize(n, vector<int>(m));
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				update(i, j, vec[i - 1][j - 1]);
	}

	void update(int x, int y, int diff)
	{
		while (x < n)
		{
			int ty = y;
			while (ty < m)
			{
				tree[x][ty] += diff;
				ty += (ty & -ty);
			}
			x += (x & -x);
		}
	}

	int query(int x, int y)
	{
		int ret = 0;
		while (x > 0)
		{
			int ty = y;
			while (ty > 0)
			{
				ret += tree[x][ty];
				ty -= (ty & -ty);
			}
			x -= (x & -x);
		}
		return ret;
	}
	int query(int sx, int sy, int ex, int ey)
	{
		return query(ex, ey) - query(sx - 1, ey) - query(ex, sy - 1) + query(sx - 1, sy-1);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	Fenwick2D fw(arr);

	while (k--)
	{
		int cmd; cin >> cmd;
		if (cmd == 1)
		{
			int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
			cout << fw.query(sx, sy, ex, ey) << "\n";
		}
		else
		{
			int x, y, d; cin >> x >> y >> d;
			int diff = d - arr[x-1][y-1];
			arr[x-1][y-1] = d;
			fw.update(x, y, diff);
		}
	}
	return 0;
}