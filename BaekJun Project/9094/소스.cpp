#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		int ans = 0;
		for (int a = 1; a < n; a++)
			for (int b = a + 1; b < n; b++)
				if ((a * a + b * b + m) % (a * b) == 0)
					ans++;

		cout << ans << "\n";
	}
	return 0;
}