#include <bits/stdc++.h>

using namespace std;

int main() {

	int y1, m1, d1, y2, m2, d2; 
	scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);

	int t = y2 - y1;

	if (m1 < m2 || (m1 == m2 && d1 <= d2)) {}
		else t--;

	printf("%d\n%d\n%d", t, y2 - y1 + 1, y2 - y1);

	return 0;

}