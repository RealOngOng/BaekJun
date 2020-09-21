#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		ll n; scanf("%lld", &n);

		ll sum = 0;
		for (int i = 0; i < n; i++) {

			ll a; scanf("%lld", &a);
			sum += a;
			sum %= n;

		}

		printf("%s\n", (sum % n) ? "NO" : "YES");

	}

	return 0;

}