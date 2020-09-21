#include <bits/stdc++.h>

using namespace std;

int main() {

	int h1, m1, s1, h2, m2, s2; 
	scanf("%d:%d:%d\n%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

	int t1 = h1 * 3600 + m1 * 60 + s1,
		t2 = h2 * 3600 + m2 * 60 + s2;

	int sub = t2 - t1;

	if (sub < 0) sub = 24 * 3600 + sub;

	int h = sub / 3600;
	sub %= 3600;
	int m = sub / 60;
	sub %= 60;
	int s = sub;

	if (h == 0 && m == 0 && s == 0) h = 24;

	printf("%02d:%02d:%02d", h, m, s);

	return 0;

}