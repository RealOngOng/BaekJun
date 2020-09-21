#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n; scanf("%lld", &n);

	long long t = 3;

	for (int i = 1; i < n; i++) t = t * 2 - 1;

	printf("%lld", t * t);

	return 0;

}