#include <iostream>
#include <limits.h>
#include <algorithm>

#define WHITE 0
#define BLACK 1

typedef struct Vector2 {

	int x, y;

};

typedef struct Area {

	Vector2 pos1, pos2;

	int color;

	bool isCollision(Vector2 vert) {

		return !(vert.x < pos1.x || vert.x > pos2.x || vert.y < pos1.y || vert.y > pos2.y);

	}
	int GetArea() {

		return std::abs((pos2.x - pos1.x) * (pos2.y - pos1.y));

	}

	void print() {

		std::cout << "(" << pos1.x << ", " << pos1.y << ") - (" << pos2.x << ", " << pos2.y
			<< ") " << ((color) ? "BLACK" : "WHITE") << "\n";

	}

};

int node_count;

Area a[60010];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int w, h, n;
	std::cin >> w >> h >> n;

	int max = -INT_MAX, min = INT_MAX;

	Area in = { {0, 0}, {w, h}, WHITE };

	a[0] = in;

	//node_count++;

	for (int i = 0; i < n; i++) {

		int x, y; std::cin >> x >> y;

		int innum = 0;

		for (innum = 0; innum < node_count; innum++)
			if (a[innum].isCollision({ x, y })) break;

		Area a1, a2;

		a1 = a2 = a[innum];

		if (a[innum].color == WHITE) {

			a1.pos1.y = y, a2.pos2.y = y;
			a1.color = a2.color = BLACK;

			//a1.print(), a2.print();

			a[innum] = a1, a[++node_count] = a2;

		}
		else {

			a1.pos2.x = x, a2.pos1.x = x;
			a1.color = a2.color = WHITE;

			//a1.print(), a2.print();

			a[innum] = a1, a[++node_count] = a2;

		}

	}

	//std::cout << "\n";

	for (int i = 0; i < node_count + 1; i++) {

		//a[i].print();

		int d = a[i].GetArea();

		max = std::max(d, max);
		min = std::min(d, min);

	}

	std::cout << max << " " << min << "\n";

	return 0;

}