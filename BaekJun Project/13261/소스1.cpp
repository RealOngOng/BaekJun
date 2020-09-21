#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//j번째까지 봤을 때, i명의 간수를 사용함, p는 최적화가 되는 어떤 k값
ll dp[801][8001];
ll arr[8001], sum[8001];

ll n, m;

ll cost(int a, int b) { return (sum[b] - sum[a - 1]) * (b - a + 1); }

void solve(int cnt, int s, int e, int l, int r) {

	if (s > e) return;
	
	int mid = (s + e) / 2;

	dp[cnt][mid] = -1;
	int w = -1;

	for (int i = l; i <= min(mid, r); i++) {
		ll v = dp[cnt - 1][i] + cost(i + 1, mid);
		if (dp[cnt][mid] == -1 || dp[cnt][mid] > v) {
			dp[cnt][mid] = v;
			w = i;
		}
	}

	solve(cnt, s, mid-1, l, w);
	solve(cnt, mid+1, e, w, r);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i <= n; i++)dp[1][i] = cost(1, i);
	for (int i = 2; i <= m; i++) solve(i, 0, n, 0, n);

	cout << dp[m][n];

	return 0;

}