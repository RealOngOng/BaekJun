#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, w, h; scanf("%d %d %d", &n ,&w, &h);

	int len = w * w + h * h;

	while (n--) {

		int a; scanf("%d", &a);

		if (a * a <= len) printf("DA\n");
		else printf("NE\n");

	}

	return 0;

}