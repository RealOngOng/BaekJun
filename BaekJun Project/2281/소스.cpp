#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

int dp[1001][1001];

int solve(int pos, int num) {

	//다 적었으면 반환
	if (num == n) return 0;
	//꽉찼을 때
	if (pos >= m)
		return solve(arr[num] + 1, num + 1) + ((pos == m) ? 1 : 0);

	int &ret = dp[pos][num];

	if (ret != -1) return ret;

	//다음행
	int dst = m - pos + 1;
	ret = solve(arr[num] + 1, num + 1) + dst * dst;

	//이어 붙이기
	if (pos + arr[num] <= m)
		ret = min(ret, solve(pos + arr[num] + 1, num + 1));

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << solve(arr[0] + 1, 1);

	return 0;

}