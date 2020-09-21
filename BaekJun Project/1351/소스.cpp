#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, ll> dp;

ll n, p, q;

ll solve(ll n) {

	if (dp.find(n) != dp.end()) return dp[n];

	dp.insert({n, solve(n / p) + solve(n / q)});

	return dp[n];

}

int main() {
	
	cin >> n >> p >> q;

	dp.insert({0, 1});

	cout << solve(n);

	return 0;

}