#include <iostream>
#include <utility>

#define MAX 501

typedef std::pair<int, int> Vector2;

Vector2 normal[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int map[MAX][MAX], dp[MAX][MAX];
int n, m;

bool isOut(Vector2 pos) { return (pos.first < 0 || pos.first > n || pos.second < 0 || pos.second > m); }

int search(Vector2 pos) {

	if (pos.first == n - 1 && pos.second == m - 1) 
		return 1;

	if (dp[pos.first][pos.second] != -1) return dp[pos.first][pos.second];

	dp[pos.first][pos.second] = 0;

	for (int i = 0; i < 4; i++) {

		Vector2 dirPos
			= { pos.first + normal[i].first, pos.second + normal[i].second };
		int value = map[pos.first][pos.second],
			front_value = map[dirPos.first][dirPos.second];

		if (!isOut(dirPos)) {

			if (value > front_value)
				dp[pos.first][pos.second] += search(dirPos);

		}

	}

	return dp[pos.first][pos.second];

}

int main() {

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j], dp[i][j] = -1;

	std::cout << search({ 0, 0 }) << "\n";

	return 0;

}