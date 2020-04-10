#include <iostream>
#include <limits.h>
#include <time.h>

#define WHITE 0
#define BLACK 1

typedef struct Vector2 {

	int x, y;

};

typedef struct Area {

	Vector2 pos1, pos2;

	bool isCollision(Vector2 vert) {

		return !(vert.x < pos1.x || vert.x > pos2.x || vert.y < pos1.y || vert.y > pos2.y);

	}
	int GetArea() {

		return (pos2.x - pos1.x) * (pos2.y - pos1.y);

	}

};

typedef struct Node {

	Area area;
	int color;
	int id = 0;
	bool leaf = true;

	Node *left = NULL, *right = NULL;

	void Print() {

		std::cout << "(" << area.pos1.x << ", " << area.pos1.y << ") - ("
			<< area.pos2.x << ", " << area.pos2.y << ") " << ((color == WHITE) ? "WHITE" : "BLACK") << "\n";

	}

};

Node node[60010];
Vector2 vec[30010];

Node* CreateNode(int id, Vector2 pos1, Vector2 pos2, int color) {

	Node *n = new Node;

	n->area.pos1 = pos1;
	n->area.pos2 = pos2;
	n->color = color;
	n->id = id;

	node[id] = *n;

	return n;

}

clock_t start, end;

int main() {

	start = clock();

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int w, h, n;
	std::cin >> w >> h >> n;

	node[0] = *CreateNode(0, { 0, 0 }, { w, h }, WHITE);

	Node *target = NULL;

	int count = n;
	int i = 1;

	for (int j = 0; j < n; j++) {

		int x, y;
		std::cin >> x >> y;

		vec[j] = { x, y };

	}

	end = clock();

	std::cout << "time : " << (double)(end - start) << "\n";

	start = clock();

	int cc = 0;

	for (int j = 0; j < n; j++) {

		int x = vec[j].x, y = vec[j].y;

		target = &node[0];

		while (target->left) {

			cc++;

			//if (target->left->area.isCollision({ x, y }))
			//	target = target->left;
			//else
			//	target = target->right;

			if (target->left->area.isCollision({ x, y }))
				target = target->left;
			else if (target->right->area.isCollision({ x, y }))
				target = target->right;
			else
				break;

		}

		node[target->id].leaf = false;
		//node[target->id].Print();

		if (target->color == WHITE) {

			target->left = CreateNode(i++, target->area.pos1, { target->area.pos2.x, y }, BLACK);
			target->right = CreateNode(i++, { target->area.pos1.x, y }, target->area.pos2, BLACK);

		}
		else {

			target->left = CreateNode(i++, target->area.pos1, { x, target->area.pos2.y }, WHITE);
			target->right = CreateNode(i++, { x, target->area.pos1.y }, target->area.pos2, WHITE);

		}

	}

	end = clock();

	std::cout << "time : " << (double)(end - start) << "\n";

	start = clock();

	std::cout << "cc : " << cc << "\n";

	//std::cout << "\n";

	int max = -INT_MAX, min = INT_MAX;

	for (int i = 0; i < 2 * n + 1; i++) {

		if (node[i].leaf) {

			int d = node[i].area.GetArea();

			//node[i].Print();

			if (d > max) max = d;
			if (d < min) min = d;

		}

	}

	std::cout << max << " " << min << "\n";

	end = clock();

	std::cout << "time : " << (double)(end - start) << "\n";

	return 0;

}