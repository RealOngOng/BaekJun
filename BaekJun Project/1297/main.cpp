#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, a, b; scanf("%d %d %d", &n, &a, &b);

	double c = sqrt(a * a + b * b);

	printf("%d %d", (int)((a * n)/c), (int)((b * n)/c));

	return 0;

}