#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b; scanf("%d %d", &a, &b);

	if (a == b) printf("%d", a);
	else printf("%d", max(a, b));

	return 0;

}