#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[1000000];

int main() {

	int tc; scanf("%d", &tc);

	while (tc--) {

		ll n, m; scanf("%lld %lld", &m, &n);

		ll sum = 0;

		for (int i = 0; i < n; i++) {

			ll a; scanf("%lld", &a);
			sum += a;

			cnt[sum % m]++;

		}

		ll ans = 0;
		ans += cnt[0];

		for (int i = 0; i < m; i++)
			ans += ((ll)cnt[i]) * ((ll)cnt[i] - 1) / 2;

		printf("%lld\n", ans);

		memset(cnt, 0, sizeof(cnt));

	}

	return 0;

}