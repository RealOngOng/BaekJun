#include <bits/stdc++.h>

using namespace std;

int mindp[3][2], maxdp[3][2];

int main() {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int arr[3];

		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[j]);

		maxdp[0][(i + 1) % 2] = max(maxdp[0][i % 2], maxdp[1][i % 2]) + arr[0];
		maxdp[1][(i + 1) % 2] = max({ maxdp[0][i % 2], maxdp[1][i % 2], maxdp[2][i % 2]}) + arr[1];
		maxdp[2][(i + 1) % 2] = max(maxdp[1][i % 2], maxdp[2][i % 2]) + arr[2];

		mindp[0][(i + 1) % 2] = min(mindp[0][i % 2], mindp[1][i % 2]) + arr[0];
		mindp[1][(i + 1) % 2] = min({ mindp[0][i % 2], mindp[1][i % 2], mindp[2][i % 2] }) + arr[1];
		mindp[2][(i + 1) % 2] = min(mindp[1][i % 2], mindp[2][i % 2]) + arr[2];

	}

	printf("%d %d\n", 
		   max({ maxdp[0][n % 2], maxdp[1][n % 2], maxdp[2][n % 2] }),
		   min({ mindp[0][n % 2], mindp[1][n % 2], mindp[2][n % 2] }));

	return 0;

}