#include <bits/stdc++.h>

#define MOD 100000

using namespace std;

typedef long long ll;

char cl[4] = { '(', '{', '[' };
char cr[4] = { ')', '}', ']' };

string str;

//x ~ y 구간의 경우의 수
ll dp[201][201];

ll solve(int l, int r) {

	if (l > r) return 1;
	if (dp[l][r] != -1) return dp[l][r];

	ll &ret = dp[l][r];
	ret = 0;

	for (int k = l + 1; k <= r; k += 2)
		for (int i = 0; i < 3; i++)
			if (str[l] == cl[i] || str[l] == '?')
				if (str[k] == cr[i] || str[k] == '?') {

					ll q = solve(l + 1, k - 1) * solve(k + 1, r);

					ret += q;

					if (ret >= MOD)
						ret = MOD + ret % MOD;

				}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	cin >> str;

	long long result = solve(0, n - 1);

	if (result >= MOD)
		printf("%05lld\n", result % MOD);
	else
		printf("%lld\n", result);

	return 0;

}