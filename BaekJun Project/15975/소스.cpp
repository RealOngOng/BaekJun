#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> color[100001];

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		int a, b; cin >> a >> b;
		color[b].push_back(a);

	}

	for (int i = 1; i <= n; i++)
		sort(color[i].begin(), color[i].end());

	ll ans = 0;

	for (int i = 1; i <= n; i++) {

		if (color[i].size() < 2) continue;

		for (int w = 0; w < color[i].size(); w++) {

			int dst = 0x3f3f3f3f;

			if (w - 1 >= 0) dst = min(dst, color[i][w] - color[i][w - 1]);
			if (w + 1 < color[i].size()) dst = min(dst, color[i][w + 1] - color[i][w]);

			ans += dst;

		}

	}

	cout << ans;

	return 0;

}