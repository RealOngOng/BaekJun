#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n), dp;
		for (int i = 0; i < n; i++) cin >> arr[i];

		for (int i = 0; i < n; i++)
		{
			int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

			if (dp.size() <= idx) dp.push_back(arr[i]);
			else dp[idx] = arr[i];
		}

		cout << dp.size() << "\n";
	}
	return 0;
}