#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c; scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c) printf("2");
	else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) printf("1");
	else printf("0");

	return 0;

}