#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {

	map<int, int> X, Y;

	for (int i = 0; i < 3; i++) {

		int x, y; scanf("%d %d", &x, &y);

		if (X.find(x) == X.end()) X.insert({ x, 1 });
		else X[x]++;
	
		if (Y.find(y) == Y.end()) Y.insert({ y, 1 });
		else Y[y]++;

	}

	int x = 0, y = 0;

	for (pi p : X) if (p.second == 1) x = p.first;
	for (pi p : Y) if (p.second == 1) y = p.first;

	printf("%d %d", x, y);

	return 0;

}