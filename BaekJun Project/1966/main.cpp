#include <bits/stdc++.h>

using namespace std;

typedef pair<int, bool> pb;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int n, m; scanf("%d %d", &n, &m);

		vector<pb> vec;
		vector<int> priroty; 

		for (int i = 0; i < n; i++) {

			int a; scanf("%d", &a);
			vec.push_back({a, i == m});
			priroty.push_back(a);

		}

		sort(priroty.begin(), priroty.end(), greater<int>());

		int cnt = 0;

		while (!vec.empty()) {

			pb top = vec[0];
			vec.erase(vec.begin());

			if (top.first == priroty[0]) {

				priroty.erase(priroty.begin());

				cnt++;

				if (top.second) break;

			}
			else
				vec.push_back(top);

		}

		printf("%d\n", cnt);

	}

	return 0;

}