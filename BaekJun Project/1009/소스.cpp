#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int a, b; scanf("%d %d", &a, &b);

		int sum = a % 10;

		for (int i = 1; i < b; i++)
			sum = (sum * a) % 10;

		if (sum == 0) sum = 10;

		printf("%d\n", sum);

	}

	return 0;

}