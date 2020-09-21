#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c, d; 
	scanf("%d %d %d %d", &a, &b, &c, &d);

	for (int i = 0; i < 3; i++) {

		int w; scanf("%d", &w);

		int cnt = 0;

		cnt += (0 < w % (a + b) && w % (a + b) <= a);
		cnt += ((0 < w % (c + d) && w % (c + d) <= c));

		printf("%d\n",cnt);

	}

	return 0;

}