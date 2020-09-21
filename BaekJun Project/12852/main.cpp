#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dp[1000001];

int main(void) {

	int n;
	scanf("%d", &n);

	dp[1] = 0;

	vector<pi> stk; stk.push_back({ 0, 0 }), stk.push_back({0, 0});

	for (int i = 2; i <= n; i++) {

		int var = i - 1;

		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			dp[i] = dp[i / 2] + 1, var = i / 2;

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1, var = i / 3;

		stk.push_back({ dp[i], var });

	}

	printf("%d\n", dp[n]);

	vector<int> vec; vec.push_back(n);

	int i = n;

	while (stk[i].second != 0) {

		vec.push_back(stk[i].second);
		i = stk[i].second;

	}

	for (int i : vec) printf("%d ", i);
	printf("\n");

	return 0;

}