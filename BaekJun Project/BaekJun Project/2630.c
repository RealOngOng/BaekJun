#include <stdio.h>

#define SIZE 128

int paper[SIZE][SIZE];

int n, white, blue;

void cut(int n, int s_x, int s_y);

int main() {

	scanf("%d", &n);

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			scanf("%d", &paper[x][y]);

	cut(n, 0, 0);
	printf("%d\n%d", white, blue);

	return 0;

}

void cut(int n, int s_x, int s_y) {

	int color = 0;

	for (int x = s_x; x < s_x + n; x++)
		for (int y = s_y; y < s_y + n; y++)
			color += paper[x][y];

	if (color == n * n) {
		blue++;
		return;
	}

	if (color == 0) {
		white++;
		return;
	}

	cut(n / 2, s_x, s_y);
	cut(n / 2, s_x + n / 2, s_y);
	cut(n / 2, s_x , s_y + n / 2);
	cut(n / 2, s_x + n / 2, s_y + n / 2);

}