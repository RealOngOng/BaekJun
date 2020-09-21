#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<bool> vec;

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	int score = 0, cnt = 0;
	
	for (bool i : vec) {

		if (i) {

			cnt++;
			score += cnt;

		}
		else
			cnt = 0;

	}

	printf("%d", score);

	return 0;

}