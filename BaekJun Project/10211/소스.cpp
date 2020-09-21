#include <bits/stdc++.h>

using namespace std;

int main() {

	int tc; scanf("%d", &tc);

	while (tc--) {

		int n; scanf("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

		int ans = -1e9, cur = 0;

		for (int i = 0; i < n; i++) {

			cur = max(arr[i], arr[i] + cur);
			ans = max(ans, cur);

		}

		printf("%d\n", ans);

	}

	return 0;

}