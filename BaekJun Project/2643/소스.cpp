#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n;
pi arr[101];
int dp[101][101][2];

bool check(pi from, pi to)
{
	return (from.first >= to.first && from.second >= to.second);
}

int solve(int pos, int top, bool rev)
{
	if (pos == n + 1) return 0;

	int &ret = dp[pos][top][rev];
	if (ret != -1) return ret;

	ret = max(ret, solve(pos+1, top, rev));

	pi now = { (rev) ? arr[top].second : arr[top].first, (rev) ? arr[top].first : arr[top].second };

	if (check(now, { arr[pos].first, arr[pos].second }))
		ret = max(ret, solve(pos+1, pos, 0) + 1);

	if (check(now, { arr[pos].second, arr[pos].first }))
		ret = max(ret, solve(pos + 1, pos, 1) + 1);

	return ret;
}

int main()
{	
	memset(dp, -1, sizeof(dp));

	cin >> n;
	arr[0].first = arr[0].second = 1001;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr + 1, arr + n + 1, [](const pi& p1, const pi& p2) -> bool
	{
		int d1 = p1.first * p1.second;
		int d2 = p2.first * p2.second;

		return d1 > d2;
	});

	cout << solve(1, 0, 0);
	return 0;
}