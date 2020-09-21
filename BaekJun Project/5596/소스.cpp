#include <bits/stdc++.h>

using namespace std;

int main() {

	int m1 = 0, m2 = 0;

	for (int i = 0; i < 4; i++) {

		int a; scanf("%d", &a);
		m1 += a;

	}
	for (int i = 0; i < 4; i++) {

		int a; scanf("%d", &a);
		m2 += a;

	}

	printf("%d", max(m1, m2));

	return 0;

}