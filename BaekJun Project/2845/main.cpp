#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b; scanf("%d %d", &a, &b);

	int cnt = a * b;

	int i = 5;

	while (i--) {

		int c; scanf("%d", &c);

		printf("%d ", c - cnt);

	}

	return 0;

}