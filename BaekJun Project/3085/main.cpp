#include <iostream>
#include <utility>

#define MAX 51

typedef std::pair<int, int> Vector2;

Vector2 normal[2] = {{0, 1}, {1, 0} };
char map[MAX][MAX];
int n;

__inline void swap(char* x, char* y) {

	char temp = *x;
	*x = *y;
	*y = temp;

}
__inline bool isOut(Vector2 pos) { return (pos.first < 0 || pos.second > n); }
__inline int Max(int x, int y) { return(x > y) ? x : y; }
int MapCheckCandy() {

	int result = 1;

	for (int i = 0; i < n-1; i++) {

		int seq = 1;

		for (int j = 0; j < n; j++) {
			
			if (map[i][j] == map[i][j + 1]) seq++;
			else  result = Max(result, seq), seq = 1;

		}

		result = Max(result, seq), seq = 1;

	}

	for (int i = 0; i < n - 1; i++) {

		int seq = 1;

		for (int j = 0; j < n; j++) {

			if (map[j][i] == map[j + 1][i]) seq++;
			else result = Max(result, seq), seq = 1;

		}

		result = Max(result, seq), seq = 1;

	}

	return result;

}

int main() {

	std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) std::cin >> map[i][j];

	int max = MapCheckCandy();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			Vector2 pos = { i, j };

			for (int d = 0; d < 2; d++) {

				Vector2 addPos
					= { pos.first + normal[d].first, pos.second + normal[d].second };

				#define MAP_POS map[pos.first][pos.second]
				#define MAP_ADDPOS map[addPos.first][addPos.second]

				if (isOut(addPos)) continue;
				if (MAP_POS == MAP_ADDPOS) continue;

				swap(&MAP_POS, &MAP_ADDPOS);

				max = Max(max, MapCheckCandy());

				swap(&MAP_POS, &MAP_ADDPOS);


			}

		}

	std::cout << max << "\n";

	return 0;

}