#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll dp[1001];

int main() {

	ll n; scanf("%lld", &n);

	for (int i = 1; i <= n; i++) 
		dp[i] = dp[i - 1] + i;

	ll sum = 0;

	for (int i = 1; i <= n; i++)
		sum += i * (i + 1) + dp[i];

	printf("%lld", sum);
	
	return 0;

}