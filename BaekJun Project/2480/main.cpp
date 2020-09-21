#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c; scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c && a == c) printf("%d", a * 1000 + 10000);
	else if (a == b) printf("%d", 1000 + a * 100);
	else if (a == c) printf("%d", 1000 + a * 100);
	else if (b == c) printf("%d", 1000 + b * 100);
	else printf("%d", max(a, max(b, c)) * 100);

	return 0;

}