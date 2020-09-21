#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int a = 0, b = 0;

	while (n--) {

		int q, p; scanf("%d %d", &q, &p);

		if (q > p) a++;
		else if (q < p) b++;

	}

	printf("%d %d", a, b);

	return 0;
	
}