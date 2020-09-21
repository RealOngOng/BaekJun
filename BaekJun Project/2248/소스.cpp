#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, l;
ll dp[32][32];

string ans;

ll solve(int n, int k)
{
	ll &ret = dp[n][k];
	if (ret != -1) return ret;
	if (n == 0 || k == 0) return ret = 1;
	
	ret = solve(n - 1, k - 1) + solve(n-1, k);

	return ret;
}

void tracking(int a, int b, long long sum)
{
	if (a == 0) return;
	if (b == 0)
	{
		for (int i = 0; i < a; i++)
			ans += '0';
		return;
	}

	ll pivot = solve(a-1, b);
	if (sum <= pivot)
	{
		ans += '0';
		tracking(a - 1, b, sum);
	}
	else
	{
		ans += '1';
		tracking(a-1, b-1, sum - pivot);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> l;

	tracking(n, m, l);

	cout << ans;

	return 0;
}