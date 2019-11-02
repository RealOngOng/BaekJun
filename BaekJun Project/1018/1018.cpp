#include <iostream>
#include <string>
#include <climits>

using namespace std;

#define BLACK 'B'
#define WHITE 'W'

char field[51][51];

char Change(char c);

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> field[i];

	int min = INT_MAX;

	char currect;

	for (int x = 0; x < n; x++) {

		for (int y = 0; y < m; y++) {

			if (x + 7 >= n || y + 7 >= m) continue;
			
			currect = field[x][y];
			int count1 = 0, count2 = 0;

			for (int w = 0; w < 8; w++) {

				for (int z = 0; z < 8; z++) {

					if (field[x + w][y + z] != currect) count1++;

					currect = Change(currect);

				}

				currect = Change(currect);

			}

			currect = Change(field[x][y]);
			int count = 0;

			for (int w = 0; w < 8; w++) {

				for (int z = 0; z < 8; z++) {

					if (field[x + w][y + z] != currect) count2++;

					currect = Change(currect);

				}

				currect = Change(currect);

			}


			if (min > count1) min = count1;
			if (min > count2) min = count2;

		}

	}

	cout << min;

	return 0;
	
}

char Change(char c) { return (c == BLACK) ? WHITE : BLACK; }