#include <bits/stdc++.h> 

using namespace std;

//i번째 숫자를 만드는 최솟값
int dp[1000001];

int main() {

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	int n; cin >> n;

	dp[n] = 0;

	for (int i = n; i > 1; i--) {

		if (i % 3 == 0)
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);

		if (i % 2 == 0)
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);

		dp[i - 1] = min(dp[i - 1], dp[i] + 1);

	}
	
	cout << dp[1];

	return 0;

}