#include <bits/stdc++.h>

using namespace std;

int main() {

	int t = 7;

	vector<int> vec;

	while (t--) {

		int a; scanf("%d", &a);

		if (a % 2 == 1) vec.push_back(a);

	}

	int m = 1e9, sum = 0;

	if (vec.size() == 0) printf("-1");
	else {

		for (int i : vec)
			m = min(m, i), sum += i;

		printf("%d\n%d", sum, m);

	}

	return 0;
	
}