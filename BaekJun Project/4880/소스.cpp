#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) break;

		if (b - a == c - b)printf("AP %d\n", c + b - a);
		else if (b / a == c / b) printf("GP %d\n", c * (c / b));

	}

	return 0;

}