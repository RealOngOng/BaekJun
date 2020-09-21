#include <bits/stdc++.h>

using namespace std;
struct Center
{
	int x, y, r;
};

int p[3001];
int find(int x)
{
	if (p[x] == 0) return x;
	else
		return p[x] = find(p[x]);
}
bool merge(int a, int b)
{
	if (a < b) swap(a, b);
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		memset(p, 0, sizeof(p));

		int n; cin >> n;
		vector<Center> arr;
		for (int i = 0; i < n; i++)
		{
			int x, y, r; cin >> x >> y >> r;
			arr.push_back({x, y, r});
		}
		
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int dx = arr[i].x - arr[j].x;
				int dy = arr[i].y - arr[j].y;
				int dst = dx * dx + dy * dy;
				if (dst > (arr[i].r + arr[j].r) * (arr[i].r + arr[j].r)) continue;
				if (merge(i, j)) ans--;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}