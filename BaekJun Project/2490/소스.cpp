#include <bits/stdc++.h>

using namespace std;

int main() {

	int t = 3;

	while (t--) {

		int sum = 0;
		for (int i = 0; i < 4; i++) {

			int n; scanf("%d", &n);
			sum += n;

		}

		if (sum == 0) printf("D\n");
		else if (sum == 4) printf("E\n");
		else printf("%c\n", 3 - sum + 'A');

	}

	return 0;

}