#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c; scanf("%d %d %d", &a, &b, &c);

	b += c;

	a += b / 60;
	b = b % 60;

	if (a >= 24) a = a % 24;

	printf("%d %d", a, b);

	return 0;

}