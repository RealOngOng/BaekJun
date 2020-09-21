#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

typedef struct Vertex {

	std::vector<int> adjust;

};

int match[MAX];
bool visit[MAX];
Vertex vert[MAX];

bool dfs(int idx) {

	int size = vert[idx].adjust.size();

	for (int i = 0; i < size; i++) {

		int adj = vert[idx].adjust[i];

		if (visit[adj]) continue;
		visit[adj] = true;

		if (match[adj] == -1 || dfs(match[adj])) {

			match[adj] = idx;
			return true;

		}

	}

	return false;

}

int main() {

	int t; std::cin >> t;

	while (t--) {

		int n, m; std::cin >> m >> n;

		for (int w = 0; w < MAX; w++) vert[w].adjust.resize(0);

		for (int i = 0; i < n; i++) {

			int a, b; std::cin >> a >> b;

			vert[i].adjust.resize(b - a + 1);

			int l = a - 1;

			for (int j = 0; j < b - a + 1; j++)
				vert[i].adjust[j] = l++;

		}

		std::fill(match, match + MAX, -1);

		int result = 0;

		for (int i = 0; i < n; i++) {

			std::fill(visit, visit + MAX, false);

			if (dfs(i)) result++;

		}

		std::cout << result << "\n";

	}

	return 0;

}