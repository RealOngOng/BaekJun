#include <bits/stdc++.h>

using namespace std;

int n;

int len[3];
int arr[3][111];
int dp[111][111][111][3];

int dst(int a, int b)
{
	int temp = abs(a - b);

	if (a < b) a += n;
	else if (a > b) b += n;

	return min(temp, abs(a - b));
}

int solve(int a, int b, int c, int w)
{
	int &ret = dp[a][b][c][w];
	if (ret != 0x3f3f3f3f) return ret;

	if (a >= len[0] && b >= len[1] && c >= len[2])
		return ret = 0;

	int order[] = { a, b, c };
	int now = arr[w][order[w]];

	if (w == 1) now += n / 3 * 2;
	else if (w == 2) now += n / 3;

	if(a < len[0])
		ret = min(ret, solve(a+1, b, c, 0) + dst(now, arr[0][a+1]));

	if(b < len[1])
		ret = min(ret, solve(a, b+1, c, 1) + dst(now, arr[1][b+1] + n/3*2));

	if(c < len[2])
		ret = min(ret, solve(a, b, c+1, 2) + dst(now, arr[2][c+1] + n/3));

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n;

	for (int i = 0; i < 3; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
			cin >> arr[i][j+1];
	}

	arr[0][0] = 1;
	arr[1][0] = n / 3 ;
	arr[2][0] = n / 3 * 2;

	cout << solve(0, 0, 0, 0) << "\n";
	return 0;
}