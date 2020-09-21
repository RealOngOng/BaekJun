#include <bits/stdc++.h>

using namespace std;

vector<int> GetPrime(int x)
{
	vector<bool> visit(x + 1);
	vector<int >ans;
	for (int i = 2; i <= x; i++)
	{
		if (visit[i]) continue;
		ans.push_back(i);
		for (int j = i; j <= x; j += i)
			visit[j] = true;
	}
	return ans;
}

int main()
{
	vector<int> prime = GetPrime(10000000);
	vector<int> dp(prime.size() + 1);
	for (int i = 1; i < dp.size(); i++)
		dp[i] = dp[i - 1] + prime[i - 1];

	function<int(int, int)> GetSum = [&](int s, int e) -> int
	{
		return dp[e + 1] - dp[s];
	};

	int n; cin >> n;

	int l = 0, r = 0;

	int ans = 0;
	int sum = prime[0];
	while (l < prime.size() - 1 || r < prime.size() - 1)
	{
		if (sum == n) ans++;
		if (l < prime.size() && r < prime.size())
		{
			if (sum < n) r++;
			else l++;
		}
		else if (l < prime.size()) l++;
		else if (r < prime.size()) r++;

		//cout << l << " " << r << "\n";
		sum = GetSum(l, r);
	}

	cout << ans;
	return 0;
}