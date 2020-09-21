#include <bits/stdc++.h>

using namespace std;

int dp[3000001];
vector<int> fibo;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	fibo.push_back(1);
	fibo.push_back(2);

	int idx = 1;
	while (fibo[idx] < 3 * 1e6)
	{
		fibo.push_back(fibo[idx] + fibo[idx - 1]);
		idx++;
	}

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	bitset<16> check;
	for (int i = 4; i <= 3000000; i++)
	{
		check.reset();

		int idx = 0;
		while (fibo[idx] <= i)
		{
			check[dp[i - fibo[idx]]] = true;
			idx++;
		}

		int top = 0;
		for (top = 0; top <= 15; top++)
			if (!check[top])
				break;

		dp[i] = top;
	}

	int n; cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;

		sum ^= dp[a];
	}

	if (sum > 0) cout << "koosaga";
	else cout << "cubelover";
	return 0;
}