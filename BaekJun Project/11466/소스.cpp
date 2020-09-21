#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b; scanf("%d %d", &a, &b);

	if (a < b) swap(a, b);

	if (a / b >= 3)printf("%d", b);
	else {

		double t1 = (double)b / 2, t2 = (double)a / 3;

		printf("%.4lf", max(t1, t2));

	}

	return 0;

}