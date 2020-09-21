#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

//i개의 그룹으로 나뉘었고, j를 볼때 최댓값
ll dp[5001][5001];
ll sum[5001][5001];

ll arr[5001];

ll cost(ll a, ll b) {
	if (a > b) swap(a, b);
	return sum[a][b];
}

void dnc(ll cnt, ll s, ll e, ll l, ll r) {

	if (s > e) return;

	ll mid = (s + e) / 2;

	ll &ret = dp[cnt][mid];

	ret = -1;
	int w = -1;

	for (int i = l; i <= min(mid, r); i++) {
		ll v = dp[cnt-1][i-1] + cost(i, mid);
		if (ret < v) {
			w = i;
			ret = v;
		}
	}

	dnc(cnt, s, mid-1, l, w);
	dnc(cnt, mid+1, e, w, r);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {

		sum[i][i] = arr[i];
		for (int j = i+1; j <= n; j++)
			sum[i][j] = sum[i][j-1] | arr[j];

	}

	for (int i = 1; i <= n; i++) dp[1][i] = cost(1, i);
	for(int i=2; i <= k; i++) dnc(i, i, n, i, n);

	cout << dp[k][n];

	return 0;

}