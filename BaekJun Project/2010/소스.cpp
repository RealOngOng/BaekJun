#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int sum = 0;

	for (int i = 1; i <= n; i++) {

		int a; scanf("%d", &a);

		if (i == n) sum += a;
		else sum += a - 1;

	}

	printf("%d", sum);

	return 0;

}