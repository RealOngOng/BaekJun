#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	printf("%d", ((n + 1) * (m + 1)) / (k + 1) - 1);

	return 0;

}