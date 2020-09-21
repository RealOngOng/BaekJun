#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int n; scanf("%d", &n);

		vector<pi> vec;

		for (int i = 1; i <= 12; i++)
			for (int j = 1; j <= 12; j++) {

				if (i == j) continue;

				if (i + j == n)
					vec.push_back({ min(i, j), max(i, j) });

			}

		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		printf("Pairs for %d: ", n);

		for (int i = 0; i < vec.size(); i++) {

			printf("%d %d", vec[i].first, vec[i].second);

			if (i != vec.size() - 1) printf(", ");

		}

		printf("\n");

	}

	return 0;

}