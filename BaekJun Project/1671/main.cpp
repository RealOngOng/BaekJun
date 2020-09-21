#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 102

typedef struct Vertex {

	std::vector<int> adjust;

};

typedef struct Shark {

	int scale, speed, smart;

	bool operator==(Shark s) { return (scale == s.scale && speed == s.speed && smart == s.smart); }
	bool operator>(Shark s) { return (scale >= s.scale && speed >= s.speed && smart >= s.smart); }
	bool operator<(Shark s) { return (scale <= s.scale && speed <= s.speed && smart <= s.smart); }

};

int match[2][MAX];
bool visit[MAX];
Vertex vert[2][MAX];
Shark sh[MAX];

bool dfs(int group, int idx) {

	int size = vert[group][idx].adjust.size();

	for (int i = 0; i < size; i++) {

		int adj = vert[group][idx].adjust[i];

		if (visit[adj]) continue;
		visit[adj] = true;

		if (match[group][adj] == -1 || dfs(group, match[group][adj])) {

			match[group][adj] = idx;
			return true;

		}

	}

	return false;

}

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> sh[i].scale >> sh[i].speed >> sh[i].smart;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i == j) continue;

			if (sh[i] == sh[j]) {

				if (i < j) {

					vert[0][2 * i].adjust.push_back(j);
					vert[0][2 * i + 1].adjust.push_back(j);

				}
				else if (i > j) {

					vert[1][2 * j].adjust.push_back(i);
					vert[1][2 * j + 1].adjust.push_back(i);

				}

			}
			else if (sh[i] > sh[j]) {

				vert[0][2 * i].adjust.push_back(j);
				vert[0][2 * i + 1].adjust.push_back(j);
				vert[1][2 * j].adjust.push_back(i);
				vert[1][2 * j + 1].adjust.push_back(i);

			}

		}

	}

	for (int q = 0; q < 2; q++) {

		std::fill(match[q], match[q] + MAX, -1);

		for (int i = 0; i < n * 2; i++) {

			std::fill(visit, visit + MAX, false);

			dfs(q, i);

		}

	}

	int result = 0;

	for (int i = 0; i < n * 2; i++)
		result += (match[0][i] != -1);

	result = n - result;

	std::cout << result << "\n";

	return 0;

}