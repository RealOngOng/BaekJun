#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 0x3f3f3f3f

//dp[i] = i원일 때 만들 수 있는 최소 개수
int dp[2 * MAX + 1];

int main() {

	int tc; cin >> tc;

	string result;

	while (tc--) {

		memset(dp, INF, sizeof(dp));

		int n, m; cin >> n >> m;
		vector<int> arr(m);

		for (int i = 0; i < m; i++) cin >> arr[i];

		dp[0] = 0;

		for (int w : arr)
			for (int i = n - 1; i >= 0; i--) {

				if (dp[i] == INF) continue;
				dp[i + w] = min(dp[i + w], dp[i] + 1);

			}

		int i = 0;

		for (i = n; dp[i] == INF; i++) {}

		cout << i << " " << dp[i] << "\n";

	}

	return 0;

}