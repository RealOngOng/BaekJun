#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());

		int ans = 0;

		for (int i = 0; i < n; i++) {

			for (int l = i - 1, r = i + 1; 0 <= l && r < n;) {

				int a = arr[i] - arr[l], b = arr[r] - arr[i];

				if (a == b) ans++, l--, r++;
				else if (a < b) l--;
				else r++;

			}

		}

		cout << ans << "\n";

	}

	return 0;

}