#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, q; scanf("%d %d", &n, &q);

	vector<int> arr(n + 1), num[4];

	for (int i = 0; i < 4; i++)
		num[i].resize(n + 1);

	for (int i = 1; i <= n; i++) {

		int a;  scanf("%d", &a);
		arr[i] = a;

		for (int j = 1; j <= 3; j++)
			num[j][i] = num[j][i - 1] + (a == j);

	}

	while (q--) {

		int a, b; scanf("%d %d", &a, &b);

		for (int i = 1; i <= 3; i++)
			printf("%d ", num[i][b] - num[i][a - 1]);

		printf("\n");

	}

	return 0;

}