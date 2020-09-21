#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
	int n; cin >> n;
	vector<pi> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());
	vector<int> vec;
	for (int i = 0; i < n; i++)
		vec.push_back(arr[i].second);

	vector<int> dp;

	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();

		if (dp.size() <= idx) dp.push_back(vec[i]);
		else dp[idx] = vec[i];
	}

	cout << n - dp.size();

	return 0;
}