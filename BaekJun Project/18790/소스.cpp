#include <bits/stdc++.h>

using namespace std;

int n;
int arr[501];
int dp[501][501];
int cache[501][501];

int solve(int pos, int cnt)
{
	if (pos >= n) return -0x3f3f3f3f;
	if (cnt == n) return 0;

	int &ret = dp[pos][cnt];
	if (ret != -1) return ret;

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		int v = solve(i, 1);
		
		if (v == n) cout << "ok\n";
	}
	return 0;
}