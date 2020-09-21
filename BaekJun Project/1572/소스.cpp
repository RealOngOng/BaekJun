#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n, k; cin >> n >> k;

	ll cnt = 0;

	vector<ll> arr(n), vec;

	for (int i = 0; i < n; i++) {

		ll a; cin >> a;

		arr[i] = a;

		if (i < k)vec.push_back(a);

	}

	sort(vec.begin(), vec.end());

	int prev = 0;

	for (int i = k; i < n; i++) {

		cnt += vec[(k + 1) / 2 - 1];

		vec.erase(lower_bound(vec.begin(), vec.end(), arr[prev]));

		vec.insert(lower_bound(vec.begin(), vec.end(), arr[i]), arr[i]);

		prev++;

	}

	cnt += vec[(k + 1) / 2 - 1];

	cout << cnt;

	return 0;

}