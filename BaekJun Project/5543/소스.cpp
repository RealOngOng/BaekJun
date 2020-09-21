#include <bits/stdc++.h>

using namespace std;

int main() {

	int m1 = 1e9, m2 = 1e9;

	for (int i = 0; i < 3; i++) {

		int a; scanf("%d", &a);

		m1 = min(m1, a);

	}
	for (int i = 0; i < 2; i++) {

		int a; scanf("%d", &a);

		m2 = min(m2, a);

	}

	printf("%d", m1 + m2 - 50);

	return 0;

}