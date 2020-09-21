#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> dp[9];

int main() {

	int k; cin >> k;

	string str_k = to_string(k);

	dp[0].insert(0);
	dp[1].insert(k);

	for (int i = 2; i <= 8; i++) {

		string str;
		for (int j = 0; j < i; j++) str += str_k;

		dp[i].insert(atoll(str.c_str()));

		for (ll w : dp[i - 1]) {

			dp[i].insert(w + k);

			dp[i].insert(w - k);
			dp[i].insert(k - w);

			dp[i].insert(w * k);

			if(w != 0) dp[i].insert(k / w);
			if(k != 0) dp[i].insert(w / k);

		}

	}

	for(int i=0; i <= 8; i++)
		for (int j = 0; j <= 8 - i; j++) {

			for(ll a : dp[i])
				for (ll b : dp[j]) {

					dp[i + j].insert(a + b);

					dp[i + j].insert(a - b);
					dp[i + j].insert(b - a);

					dp[i + j].insert(a * b);

					if(b != 0) dp[i + j].insert(a / b);
					if(a != 0) dp[i + j].insert(b / a);

				}

		}

	int tc; cin >> tc;

	while (tc--) {

		ll n; cin >> n;

		int ans = -1;

		for(int i=0; i <= 8; i++)
			if (dp[i].find(n) != dp[i].end()) {
				ans = i;
				break;
			}

		if (ans == -1) cout << "NO\n";
		else cout << ans << "\n";

	}

}