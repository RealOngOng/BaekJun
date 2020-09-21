#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)break;

		int a2 = a * a, b2 = b * b, c2 = c * c;

		if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) printf("right\n");
		else printf("wrong\n");

	}

	return 0;

}