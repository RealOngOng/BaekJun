#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int temp = 1;
	int sum = 0, add = 2;

	while (temp <= n) {

		sum += add;

		if (temp > 1 && temp % 2 == 1) add++;

		temp++;

	}

	printf("%d", sum);

	return 0;

}