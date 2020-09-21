#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> arr(n), dp;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx >= dp.size()) dp.push_back(arr[i]);
		else dp[idx] = arr[i];
	}

	cout << dp.size();
	return 0;
}