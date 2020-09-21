#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;

		int ans = 0;

		for (int i = 0; i < n; i++) {

			int m = -1e9;

			for (int j = 0; j < 3; j++) {

				int a; cin >> a;
				m = max(m, a);

			}

			if (m > 0) ans += m;
			

		}

		cout << ans << "\n";

	}

	return 0;

}