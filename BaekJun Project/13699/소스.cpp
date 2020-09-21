#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[36];

int main()
{
	dp[0] = 1;
	
	for (int i = 1; i <= 35; i++)
		for (int j = 0; j <= i - 1; j++)
			dp[i] += dp[j] * dp[i - j - 1];

	int n; cin >> n;
	cout << dp[n];
	return 0;
}