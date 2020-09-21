#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int n; scanf("%d", &n);

		int sum = 0;

		for (int i = 2; i <= n; i++) {

			if (n % i > 0) continue;

			int pw = i;

			while (true) {

				if (n % pw > 0) break;

				sum++;
				pw *= i;

			}

		}

		printf("%d\n", sum);

	}

	return 0;
	
}