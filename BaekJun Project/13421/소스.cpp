#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef struct Vector2 {

	ll x, y;

};

vector<Vector2> pos;

ll dx[4] = { 1, -1, -1, 1 };
ll dy[4] = { 1, 1, -1, -1 };

ll f(ll len) {

	vector<int> visit = { 0, 1, 2, 3 };

	ll ans = 1e18;

	do {

		ll v = 0;

		for (int i = 0; i < 4; i++)
			v += abs(len * dx[visit[i]] - pos[i].x) + abs(len * dy[visit[i]] - pos[i].y);

		ans = min(ans, v);

	} while (next_permutation(visit.begin(), visit.end()));

	return ans;

}

int main() {

	pos.resize(4);
	for (int i = 0; i < 4; i++) {

		int x, y; cin >> x >> y;
		pos[i].x = x, pos[i].y = y;

	}

	ll ans = -1;
	ll cost = 1e18;

	vector<int> visit = { 0, 1, 2, 3 };

	do {

		set<ll> arr;

		for (int i = 0; i < 4; i++) {

			arr.insert(abs(pos[i].x * dx[visit[i]]));
			arr.insert(abs(pos[i].y * dy[visit[i]]));

		}

		for (ll w : arr) {

			ll v = f(w);

			if (v <= cost) {

				cost = v;
				ans = max(ans, w);

			}

		}

	} while (next_permutation(visit.begin(), visit.end()));

	cout << max(ans * 2, 1ll);

	return 0;

}