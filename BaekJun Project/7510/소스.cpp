#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int t; scanf("%d", &t);

	int n = 0;

	while (t--) {

		n++;

		ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);

		ll a2 = a * a, b2 = b * b, c2 = c * c;

		printf("Scenario #%d:\n", n);

		if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) printf("yes\n\n");
		else printf("no\n\n", n);

	}

	return 0;

}