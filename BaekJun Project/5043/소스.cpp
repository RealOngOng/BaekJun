#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, b; scanf("%lld %lld", &n, &b);

	long long sum = 0;

	while (n) {

		n /= 2;
		sum++;

	}

	sum--;

	printf("%s", (sum <= b) ? "yes" : "no");

	return 0;

}