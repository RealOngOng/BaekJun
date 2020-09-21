#include <bits/stdc++.h>

using namespace std;

//왼쪽 더미 n개, 오른쪽 더미 m개 있을 때 최솟값
int dp[2001][2001];

vector<int> A, B;

int solve(int a, int b) {

	if (a == 0 || b == 0) return 0;

	int &ret = dp[a][b];

	if (ret != -1) return ret;

	if (A[a] > B[b])
		ret = max(ret, solve(a, b - 1) + B[b]);
	else {
		ret = max(ret, solve(a - 1, b - 1));
		ret = max(ret, solve(a - 1, b));
	}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	int n; cin >> n;

	A.resize(n + 1), B.resize(n + 1);

	for (int i = n; i >= 1; i--)
		cin >> A[i];

	for (int i = n; i >= 1; i--)
		cin >> B[i];

	cout << solve(n, n);

	return 0;

}