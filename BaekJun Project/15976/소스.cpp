#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

vector<pi> X, Y;
vector<ll> sum;

ll GetSum(int a, int b) {

	int s, e;
	s = lower_bound(Y.begin(), Y.end(), make_pair(a, 0)) - Y.begin();
	e = lower_bound(Y.begin(), Y.end(), make_pair(b, 0)) - Y.begin();
	return sum[e] - sum[s];

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n;

	for (int i = 0; i < n; i++) {

		int a, b; cin >> a >> b;
		X.push_back({a, b});

	}

	cin >> m;

	for (int i = 0; i < m; i++) {

		int a, b; cin >> a >> b;
		Y.push_back({a, b});

	}

	sort(Y.begin(), Y.end());

	int a, b; cin >> a >> b;

	sum.push_back(0);
	for (int i = 0; i < m; i++)
		sum.push_back(sum[i] + Y[i].second);

	ll ans = 0;
	for (pi p : X)
		ans += (ll)p.second * GetSum(p.first + a, p.first + b + 1);

	cout << ans;

	return 0;

}