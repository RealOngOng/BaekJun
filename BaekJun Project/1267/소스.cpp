#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> vec;
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	int y = 0, m = 0;

	for (int t : vec) {

		y += (t / 30 + 1) * 10;
		m += (t / 60 + 1) * 15;

	}

	if (y == m) printf("Y M %d", y);
	else if (y < m) printf("Y %d", y);
	else printf("M %d", m);

	return 0;

}