#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, r, c; scanf("%lld %lld %lld", &n, &r, &c);

	printf("%lld", (long long)(ceil((long double)n / c) * ceil((long double)r / c)));

	return 0;

}