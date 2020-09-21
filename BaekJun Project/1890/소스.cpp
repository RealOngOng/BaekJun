#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[101][101];
ll dp[101][101];

ll solve(int nx, int ny) {

	if (nx == n && ny == n) 
		return 1;

	ll &ret = dp[nx][ny];

	if (ret > 0) return ret;

	if (arr[nx][ny] == 0) return ret;

	if(nx + arr[nx][ny] <= n)
		ret += solve(nx + arr[nx][ny], ny);

	if(ny + arr[nx][ny] <= n)
		ret += solve(nx, ny + arr[nx][ny]);

	return ret;

}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	cout << solve(1, 1);

	return 0;

}