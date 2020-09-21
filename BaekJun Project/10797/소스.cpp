#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);
	int sum = 0;

	for (int i = 0; i < 5; i++) {

		int a; scanf("%d", &a);
		if (a == n) sum++;

	}

	printf("%d", sum);

	return 0;

}