#include <bits/stdc++.h>

using namespace std;

typedef struct Line
{
	int a, b, w;
};

int p[1001];

int find(int x)
{
	if (p[x] == -1) return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b)return;
	p[b] = a;
}

int main()
{
	memset(p, -1, sizeof(p));

	int n, m; cin >> n >> m;
	int s, e; cin >> s >> e;

	vector<Line> arr;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		arr.push_back({a, b, w});
	}

	sort(arr.begin(), arr.end(), [&](const Line& l1, const Line& l2) -> bool
	{
		return l1.w > l2.w;
	});

	for (Line l : arr)
	{
		merge(l.a, l.b);
		if (find(s) == find(e))
		{
			cout << l.w;
			break;
		}
	}
	return 0;
}