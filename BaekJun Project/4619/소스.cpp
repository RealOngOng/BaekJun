#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int b, n; scanf("%d %d", &b, &n);

		if (b == 0 && n == 0) break;

		int a = 1;

		while (pow(a, n) <= b)
			a++;

		int t1 = abs(b - pow(a - 1, n)), t2 = abs(b - pow(a, n));

		if (t1 < t2) printf("%d\n", a - 1);
		else printf("%d\n", a);

	}

	return 0;
	
}