#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, l, d; scanf("%d %d %d", &n, &l, &d);

	vector<bool> vec;

	while (n--) {

		for (int i = 0; i < l; i++) vec.push_back(false);
		for (int i = 0; i < 5; i++) vec.push_back(true);

	}

	int w = d;

	while (true) {

		if (vec.size() - 1 <= w) break;
		if (vec[w]) break;

		w += d;

	}

	printf("%d", w);

	return 0;

}