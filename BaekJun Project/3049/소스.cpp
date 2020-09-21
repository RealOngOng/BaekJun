#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll n; scanf("%lld", &n);

	ll vert = 1;

	for (int i = 1; i <= 4; i++)
		vert = vert * (n - i + 1) / i;

	printf("%lld", vert);

	return 0;

}