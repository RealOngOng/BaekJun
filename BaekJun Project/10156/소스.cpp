#include <bits/stdc++.h>

using namespace std;

int main() {

	int k, n, m; scanf("%d %d %d", &k, &n, &m);

	printf("%d", ((k * n - m < 0) ? 0 : k * n - m));

	return 0;

}