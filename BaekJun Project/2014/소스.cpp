#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct cmp {
	bool operator()(ll a, ll b) { return a > b; }
};

int main() {

	int n, k; cin >> n >> k;
	vector<ll> arr(n);
	priority_queue<ll, vector<ll>, cmp> pq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	set<ll> visit;

	ll ans = 0, maxValue = 0;

	for (int i = 0; i < k; i++) {

		ll top = pq.top(); pq.pop();

		for (ll w : arr) {
			ll m = w * top;
			if (pq.size() > k && m > maxValue) continue;
			if (visit.find(m) != visit.end()) continue;
			visit.insert(m);
			pq.push(m);
			maxValue = max(maxValue, m);
		}

		ans = top;

	}

	cout << ans;

	return 0;

}