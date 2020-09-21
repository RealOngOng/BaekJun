#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int sum = 0;

	for (int i = 0; i < 9; i++) {

		int a; scanf("%d", &a);
		sum += a;

	}

	printf("%d", n - sum);

	return 0;

}