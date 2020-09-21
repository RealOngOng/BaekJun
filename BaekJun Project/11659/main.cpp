#include <bits/stdc++.h>

using namespace std;

int arr[100001], dp[100001];

int sum(int a, int b) { return (dp[b] - dp[a - 1]); }

int main() {

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + arr[i];

	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		printf("%d\n", sum(a, b));

	}

	return 0;

}