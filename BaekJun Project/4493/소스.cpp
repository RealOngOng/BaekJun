#include <bits/stdc++.h>

using namespace std;

int rps(char c1, char c2) { //0ºñ±è 1 ¿ŞÂÊÀÌ ÀÌ±è 2 ¿À¸¥ÂÊÀÌ ÀÌ±è

	if (c1 == c2) return 0;

	if ((c1 == 'R' && c2 == 'S') ||
		(c1 == 'P' && c2 == 'R') ||
		(c1 == 'S' && c2 == 'P')) return 1;

	if ((c2 == 'R' && c1 == 'S') ||
		(c2 == 'P' && c1 == 'R') ||
		(c2 == 'S' && c1 == 'P')) return 2;

}

int main() {

	int t; scanf("%d", &t);

	for (int i = 0; i < t; i++) {

		int w; scanf("%d", &w);

		int a = 0, b = 0;

		for (int j = 0; j < w; j++) {

			char p1, p2; scanf(" %c  %c", &p1, &p2);

			int r = rps(p1, p2);

			if (r == 0) {}
			else if (r == 1) a++;
			else if (r == 2) b++;

		}

		if (a == b) printf("TIE\n");
		else if (a > b) printf("Player 1\n");
		else printf("Player 2\n");

	}

	return 0;

}