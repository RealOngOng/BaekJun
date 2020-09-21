#include <bits/stdc++.h>

using namespace std;

int p[100001];

int find(int x)
{
	if (p[x] == x) return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b)
{
	p[a] = b;
}

int main()
{
	for (int i = 0; i <= 100000; i++) p[i] = i;

	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a; cin >> a;
		if (find(a))
		{
			ans++;
			merge(find(a), find(a) - 1);
		}
		else
			break;
	}
	cout << ans;
	return 0;
}