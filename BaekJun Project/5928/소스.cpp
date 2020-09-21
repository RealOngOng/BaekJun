#include <bits/stdc++.h>

using namespace std;

int main() {

	int d, h, m; scanf("%d %d %d", &d, &h, &m);

	int t = d * 1440 + h * 60 + m - 16511;

	if (t >= 0) printf("%d", t);
	else printf("-1");

	return 0;

}