#include <bits/stdc++.h>

using namespace std;

char star[4000][6500];

void printStar(int _vertex, int _height) {

	star[_height][_vertex] = 
	star[_height + 1][_vertex - 1] = 
	star[_height + 1][_vertex + 1] =
	star[_height + 2][_vertex - 2] =
	star[_height + 2][_vertex - 1] =
	star[_height + 2][_vertex] =
	star[_height + 2][_vertex + 1] =
	star[_height + 2][_vertex + 2] = '*';

}

int n;

void setStar(int h, int x, int y) {

	if (h == 3) {

		printStar(x, y);
		return;

	}

	int half = h / 2;

	setStar(half, x, y);
	setStar(half, x + half, y + half);
	setStar(half, x - half, y + half);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;

	memset(star, ' ', sizeof(star));
	setStar(n, n - 1, 0);
	
	string result;
	for (int x = 0; x < n; x++) {

		for (int y = 0; y < n * 2; y++)
			result += star[x][y];

		result += "\n";

	}

	cout << result;

	return 0;

}