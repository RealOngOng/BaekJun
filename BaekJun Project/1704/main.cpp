#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

typedef struct Result {

	int count, last;
	bool visit[15][15];

};

int n, m;
bool field[15][15], visit[15][15];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int fm = 1e9;

vector<Result> route;

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= m || pos.y >= n); }

void Flip(Vector2 pos) {

	field[pos.x][pos.y] = !field[pos.x][pos.y];

	for (int i = 0; i < 4; i++) {

		Vector2 front = { pos.x + dx[i], pos.y + dy[i] };

		if (isOut(front)) continue;

		field[front.x][front.y] = !field[front.x][front.y];

	}

}

// 0 뒤집으면 안됨, 1 무조건 뒤집어야됨 2 둘 중에 상관없음 
int isFlip(Vector2 pos) {

	if (pos.x == 0) return 2;

	return field[pos.x - 1][pos.y];

}

bool isOk() {

	int sum = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			sum += field[i][j];

	return (sum == 0);

}

Vector2 IdxToVector2(int idx) { return { idx / n, idx % n }; }

void backtrack(int idx, int count) {

	if (count > fm) return;

	if (idx == n * m) {

		if (!isOk()) return;

		if (count <= fm) {

			Result r; r.count = count;

			int last = 0, q = 0;

			for (int i = 0; i < m; i++)
				for (int j = n - 1; j >= 0; j--) {

					r.visit[i][j] = visit[i][j];
					if (r.visit[i][j])
						last = q;

					q++;

				}

			r.last = last;

			route.push_back(r);
			fm = count;

		}

		return;

	}

	Vector2 pos = IdxToVector2(idx);

	int r = isFlip(pos);

	if (r == 0) backtrack(idx + 1, count);
	else if (r == 1) {

		visit[pos.x][pos.y] = true;
		Flip(pos);
		backtrack(idx + 1, count + 1);
		visit[pos.x][pos.y] = false;
		Flip(pos);

	}
	else if (r == 2) {

		backtrack(idx + 1, count);

		visit[pos.x][pos.y] = true;
		Flip(pos);
		backtrack(idx + 1, count + 1);
		visit[pos.x][pos.y] = false;
		Flip(pos);

	}

}

int main() {

	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &field[i][j]);

	backtrack(0, 0);

	if (route.size() == 0) printf("IMPOSSIBLE\n");
	else {

		sort(route.begin(), route.end(),
			 [](const Result& r1, const Result& r2) -> bool {

			if (r1.count != r2.count) return r1.count < r2.count;

			return r1.last < r2.last;

		});

		for (int i = 0; i < m; i++) {

			for (int j = 0; j < n; j++)
				printf("%d ", route[0].visit[i][j]);

			printf("\n");

		}

	}

	return 0;

}