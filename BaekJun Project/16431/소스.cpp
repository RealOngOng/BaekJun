#include <bits/stdc++.h>

using namespace std;

int main() {

	int bx, by, dx, dy, zx, zy; 
	scanf("%d %d %d %d %d %d", &bx, &by, &dx, &dy, &zx, &zy);

	int ddst = max(abs(bx - zx), abs(by - zy));
	int bdst = abs(zx - dx) + abs(zy - dy);

	if (bdst == ddst) printf("tie");
	else if (bdst < ddst) printf("daisy");
	else printf("bessie");

	return 0;

}