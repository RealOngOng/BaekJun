#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[1000];

int main() {

	ll n, m; scanf("%lld %lld", &n, &m);

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

	printf("%lld", ans);

	return 0;

}