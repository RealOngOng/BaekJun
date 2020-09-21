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

	int n, m, k; std::cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {

		int a; std::cin >> a;

		vert[i].adjust.resize(a);

		for (int j = 0; j < a; j++)
			std::cin >> vert[i].adjust[j];

	}

	int cnt = 0;

	std::fill(match, match + MAX, -1);

	int a = 0;

	for (int i = 0; i < n; i++) {

		std::fill(visit, visit + MAX, false);

		if (dfs(i)) a++;

	}

	int b = 0;

	for (int i = 0; i < n; i++) {

		std::fill(visit, visit + MAX, false);

		if (b >= k) break;

		if (dfs(i)) b++;

	}

	std::cout << a + b << "\n";

	return 0;

}