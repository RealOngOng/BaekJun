#include <bits/stdc++.h>

using namespace std;

double solve(int a, int b, int c, int d) { return((double)a / (double)c + (double)b / (double)d); }

int main() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	double max = 0; int rot = 0;

	if (max <= solve(b, d, a, c)) { max = solve(b, d, a, c), rot = 3; }
	if (max <= solve(d, c, b, a)) { max = solve(d, c, b, a), rot = 2; }
	if (max <= solve(c, a, d, b)) { max = solve(c, a, d, b), rot = 1; }
	if (max <= solve(a, b, c, d)) { max = solve(a, b, c, d), rot = 0; }

	printf("%d\n", rot);

	return 0;

}