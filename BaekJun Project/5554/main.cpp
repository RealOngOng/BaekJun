#include <bits/stdc++.h>

using namespace std;

int main() {

	int i = 4;

	int sum = 0;

	while (i--) {

		int a; scanf("%d", &a);
		sum += a;

	}

	printf("%d %d", sum / 60, sum % 60);

	return 0;

}