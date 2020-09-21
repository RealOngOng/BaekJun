#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int n, m, k; cin >> n >> m >> k;

		vector<int> arr(n);
		for (int i = 0; i < n; i++)cin >> arr[i];

		int l = 0, r = m - 1;
		int now = 0;
		for (int i = l; i <= r; i++) now += arr[i];

		int ans = 0;

		if (n == m)
			ans += (now < k);
		else {

			for (int i = 0; i < n; i++) {

				if (now < k) ans++;

				l++;
				r++;
				if (r == n) r = 0;

				now -= arr[l - 1];
				now += arr[r];

			}

		}

		cout << ans << "\n";

	}

	return 0;

}