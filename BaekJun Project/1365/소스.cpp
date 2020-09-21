#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> arr(n), dp;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int w : arr)
	{
		int idx = lower_bound(dp.begin(), dp.end(), w) - dp.begin();

		if (dp.size() <= idx) dp.push_back(w);
		else dp[idx] = w;
	}

	cout << n - dp.size();
	return 0;
}