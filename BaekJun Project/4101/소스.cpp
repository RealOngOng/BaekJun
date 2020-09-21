#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int a, b; scanf("%d %d", &a, &b);

		if (a == 0 && b == 0) break;

		printf("%s\n", (a > b) ? "Yes" : "No");

	}

	return 0;

}