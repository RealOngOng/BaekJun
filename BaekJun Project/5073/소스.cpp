#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		vector<int> vec;

		for (int i = 0; i < 3; i++) {

			int w; scanf("%d", &w);
			vec.push_back(w);

		}

		sort(vec.begin(), vec.end(), greater<int>());

		int a = vec[0], b = vec[1], c = vec[2];

		if (a == 0 && b == 0 && c == 0) break;

		if (a == b && b == c) printf("Equilateral\n");
		else if (a >= b + c)  printf("Invalid\n");
		else if (a == b || b == c || a == c) printf("Isosceles\n");
		else printf("Scalene\n");

	}

	return 0;

}