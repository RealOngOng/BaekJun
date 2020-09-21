#include <bits/stdc++.h>

using namespace std;

int dst[51][51];
int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n; cin >> n;
	while (true)
	{
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		dst[a][b] = dst[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int ans = 0x3f3f3f3f;
	vector<int> candidate;
	for (int i = 1; i <= n; i++)
	{
		int d = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			d = max(d, dst[i][j]);
		}
		
		if (d == 0x3f3f3f3f) continue;

		if (d < ans)
		{
			candidate.clear();
			ans = d;
			candidate.push_back(i);
		}else if (d == ans) candidate.push_back(i);
	}

	cout << ans << " " << candidate.size() << "\n";
	for (int w : candidate)
		cout << w << " ";
	return 0;
}