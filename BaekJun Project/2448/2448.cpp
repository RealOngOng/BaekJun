#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool star[4000][6500];

void printStar(int _vertex, int _height) {

	star[_height][_vertex] = true;

	star[_height + 1][_vertex - 1] = true;
	star[_height + 1][_vertex] = false;
	star[_height + 1][_vertex + 1] = true;

	star[_height + 2][_vertex - 2] = true;
	star[_height + 2][_vertex - 1] = true;
	star[_height + 2][_vertex] = true;
	star[_height + 2][_vertex + 1] = true;
	star[_height + 2][_vertex + 2] = true;

}

int n;

void setStar(int h, int x, int y) {

	if (h == 3) {

		printStar(x, y);
		return;

	}

	setStar(h / 2, x, y);
	setStar(h / 2, x + (h / 2), y + (h / 2));
	setStar(h / 2, x - (h / 2), y + (h / 2));

}

int main() {

	cin >> n;

	setStar(n, n - 1, 0);
	
	for (int x = 0; x < n; x++) {

		for (int y = 0; y < n*2; y++) {

			cout << ((star[x][y]) ? "*" : " ");

		}

		cout << endl;

	}

	return 0;

}