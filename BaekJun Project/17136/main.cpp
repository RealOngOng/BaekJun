#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int paper[5] = { 0, 0, 0, 0, 0 };

bool field[10][10];

int cnt = 1e9;

bool isOut(Vector2 pos) { return(pos.x < 0 || pos.y < 0 || pos.x > 10 || pos.y > 10); }

bool isSquare(Vector2 pos, int size) {

	bool ok = true;

	for (int x = pos.x; x < pos.x + size; x++)
		for (int y = pos.y; y < pos.y + size; y++)
			if (!field[x][y])
				ok = false;

	return ok;

}

void putSquare(Vector2 pos, int size, bool b) {

	for (int x = pos.x; x < pos.x + size; x++)
		for (int y = pos.y; y < pos.y + size; y++)
			field[x][y] = b;

}

void backtrack(int num) {

	Vector2 pos;

	while (!field[pos.x][pos.y])
	{
		if (++pos.x >= 10)
		{
			if (++pos.y >= 10)
			{
				cnt = min(cnt, num);
				return;
			}
			pos.x = 0;
		}
	}

	if (cnt <= num) return;

	for (int i = 5; i > 0; --i) {

		Vector2 dir = { pos.x + i, pos.y + i };

		if (isOut(dir) || paper[i] == 5) continue;
		if (!isSquare(pos, i)) continue;

		putSquare(pos, i, false);
		++paper[i];

		backtrack(num + 1);

		putSquare(pos, i, true);
		--paper[i];

	}

}

int main() {

	int all = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &field[i][j]), all += field[i][j];

	if (all == 100) {

		printf("4\n");
		return 0;

	}

	backtrack(0);

	if (cnt == 1e9) cnt = -1;

	printf("%d\n", cnt);

	return 0;

}