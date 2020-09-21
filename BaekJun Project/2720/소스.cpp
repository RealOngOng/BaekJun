#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	int coin[4] = { 250, 100, 50, 10 };

	int arr[4] = { 0, };

	while (t--) {

		int a; scanf("%d", &a);
		a *= 10;

		for (int i = 0; i < 4; i++) {

			arr[i] = a / coin[i];
			a %= coin[i];

		}

		printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);

	}

	return 0;

}