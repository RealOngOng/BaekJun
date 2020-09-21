#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);

	c += d;

	b += c / 60;
	c = c % 60;

	a += b / 60;
	b = b % 60;

	if (a >= 24) a = a % 24;

	printf("%d %d %d", a, b, c);

	return 0;

}