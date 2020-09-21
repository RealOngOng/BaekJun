#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int t = n % 8;

	if (t == 0) t = 2;
	else if (t >= 6) t = 10 - t;

	printf("%d", t);

	return 0;
	
}