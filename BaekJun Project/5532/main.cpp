#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, a, b, c, d; scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

	int m = max(ceil((double)a / c), ceil((double)b / d));
	
	printf("%d", n - m);

	return 0;

}