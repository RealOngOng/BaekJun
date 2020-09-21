#include <bits/stdc++.h>

using namespace std;

int main() {

	int n = 0;

	while (true) {

		n++;

		double a, b, c; scanf("%lf %lf %lf", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) break;

		double a2 = a * a, b2 = b * b, c2 = c * c;

		if (a == -1) {

			if (c2 - b2 <= 0) printf("Triangle #%d\nImpossible.\n\n", n);
			else printf("Triangle #%d\na = %.3lf\n\n", n, sqrt(c2 - b2));

		}
		else if (b == -1) {

			if (c2 - a2 <= 0) printf("Triangle #%d\nImpossible.\n\n", n);
			else printf("Triangle #%d\nb = %.3lf\n\n", n, sqrt(c2 - a2));

		}
		else if (c == -1) {

			if (a2 + b2 <= 0) printf("Triangle #%d\nImpossible.\n\n", n);
			else printf("Triangle #%d\nc = %.3lf\n\n", n, sqrt(a2 + b2));

		}

	}

	return 0;

}