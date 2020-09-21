#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c, d, p; scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	int x = a * p;
	int y = 0;

	if (p <= c) y = b;
	else y = b + (p - c) * d;

	printf("%d", min(x, y));

	return 0;
	
}