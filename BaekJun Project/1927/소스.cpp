#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	while (n--) {

		ll a; cin >> a;

		if (a == 0) {

			if (pq.empty()) cout << "0\n";
			else {

				cout << pq.top() << "\n";
				pq.pop();

			}

		}
		else
			pq.push(a);

	}

	return 0;

}