#include <bits/stdc++.h>

using namespace std;

int main() {

	int x1, y1, z1, x2, y2, z2;
	scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);

	printf("%d %d %d", x2 - z1, y2 / y1, z2 - x1);

	return 0;

}