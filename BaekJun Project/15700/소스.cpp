#include <bits/stdc++.h>

using namespace std;

int main() {

	long long a, b; scanf("%lld %lld", &a, &b);

	// a > b
	if (a < b) swap(a, b);

	if (a % 2 == 0) printf("%lld", a / 2 * b);
	else if (a % 2 == 1) printf("%lld", a / 2 * b + b / 2);

	return 0;

}