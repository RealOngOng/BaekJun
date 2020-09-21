#include <bits/stdc++.h>

using namespace std;

bool field[101][101];

int main() {

	int t = 4;

	while (t--) {

		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				field[i][j] = true;

	}

	int result = 0;

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			result += field[i][j];

	printf("%d\n", result);

	return 0;

}