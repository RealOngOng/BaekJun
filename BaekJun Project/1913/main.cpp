#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int field[1000][1000];

int main() {

	int n, m; scanf("%d %d", &n, &m);

	int num = n * n;
	int t = n, count = 1, dir = 0;

	int x = 0, y = -1;

	int rx = 0, ry = 0;

	while (true) {

		if (num == 0) break;

		for (int i = 0; i < t; i++) {

			x += dx[dir], y += dy[dir];

			if (num == m) rx = x, ry = y;

			field[x][y] = num--;

		}

		count++;
		if (count == 2)
			t--, count = 0;

		dir = (++dir) % 4;

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++)
			printf("%d ", field[j][i]);

		printf("\n");

	}

	printf("%d %d\n", ry + 1, rx + 1);

	return 0;

}