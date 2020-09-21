#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int p[10001];
ll cost[10001];

int find(int x) {
	if (p[x] == 0) return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b)
		p[b] = a;
}

int main() {

	memset(cost, 0x3f3f3f3f3f3f, sizeof(cost));

	ll n, m, k; cin >> n >> m >> k;
	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	
	vector<vector<int>> fr(n + 1, vector<int>());
	for (int i = 1; i <= n; i++)
		fr[find(i)].push_back(i);

	for (int i = 1; i <= n; i++) {
		if (fr[i].size() == 0) continue;
		int p = find(fr[i][0]);
		for (int w : fr[i])
			cost[p] = min(cost[p], arr[w]);
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (fr[i].size() == 0) continue;
		sum += cost[find(fr[i][0])];
	}

	if (sum > k) cout << "Oh no\n";
	else cout << sum;

	return 0;

}