#include <bits/stdc++.h>

using namespace std;

int main() {

	int t = 5, m = 0, idx = 0;

	for (int i = 0; i < 5; i++) {

		int sum = 0;

		for (int i = 0; i < 4; i++) {

			int a; scanf("%d", &a);
			sum += a;

		}

		if (m < sum) {

			m = sum;
			idx = i + 1;

		}

	}

	printf("%d %d", idx, m);

	return 0;

}