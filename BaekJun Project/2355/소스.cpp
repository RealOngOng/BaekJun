#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll a, b; scanf("%lld %lld", &a, &b);

	if (a > b) swap(a, b);

	ll ab = a + b;

	ll sum = (b - a + 1) / 2 * ab;

	if ((b - a) % 2 == 0) sum += ab / 2;

	printf("%lld", sum);

	return 0;

}