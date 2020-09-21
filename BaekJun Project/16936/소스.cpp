#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pi> pii;

int main() {

	int n; cin >> n;

	vector<pii> arr(n);

	for (int i = 0; i < n; i++) {

		ll a; cin >> a;
		ll temp = a;

		int n2 = 0, n3 = 0;

		while (true) {

			if (a % 2 != 0) break;

			a /= 2;
			n2++;

		}

		while (true) {

			if (a % 3 != 0) break;

			a /= 3;
			n3++;

		}

		arr[i] = { temp, {n3, n2} };


	}

	sort(arr.begin(), arr.end(), [](const pii& p1, const pii& p2) -> bool {

		if (p1.second.first != p2.second.first) return p1.second.first > p2.second.first;
		return p1.first < p2.first;

	});

	for (pii &w : arr)
		cout << w.first << " ";

	return 0;

}