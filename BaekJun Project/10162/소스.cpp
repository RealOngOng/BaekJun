#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int a = n / 300,
		b = n % 300 / 60,
		c = (n % 300 % 60) / 10;

	n -= a * 300 + b * 60 + c * 10;

	if (n > 0) printf("-1");
	else printf("%d %d %d", a, b, c);

	return 0;

}