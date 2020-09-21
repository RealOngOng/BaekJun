#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, t, c, p; scanf("%d %d %d %d", &n, &t, &c, &p);

	printf("%d\n", (n - 1) / t * c * p);

	return 0;

}