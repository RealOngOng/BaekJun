#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator<(Vector2 vec) {

		if (x != vec.x) return x < vec.x;
		return y < vec.y;

	}
	bool operator>(Vector2 vec) {

		if (x != vec.x) return x > vec.x;
		return y > vec.y;

	}
	bool operator==(Vector2 vec) { return (x == vec.x && y == vec.y); }

};

typedef struct Vertex {

	Vector2 pos;
	vector<int> adj;

};

int n;
Vector2 start, dst;

vector<Vertex> arr;
bool visit[102];

int distance(Vector2 v1, Vector2 v2) {return abs(v1.x - v2.x) + abs(v1.y - v2.y);}

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		scanf("%d %d", &start.x, &start.y);
		arr.push_back({ start });

		for (int i = 0; i < n; i++) {

			int x, y; scanf("%d %d", &x, &y);
			arr.push_back({ {x, y} });

		}

		scanf("%d %d", &dst.x, &dst.y);
		arr.push_back({ dst });

		for (int i = 0; i < n + 2; i++)
			for (int j = 0; j < n + 2; j++) {

				if (i == j) continue;

				if (distance(arr[i].pos, arr[j].pos) <= 1000)
					arr[i].adj.push_back(j);

			}

		bool result = false;

		queue<Vertex> q;

		q.push(arr[0]);
		visit[0] = true;

		while (!q.empty()) {

			Vertex top = q.front(); q.pop();

			if (top.pos == dst) {

				result = true;
				break;

			}

			for (int w : top.adj) {

				if (visit[w]) continue;

				visit[w] = true;
				q.push(arr[w]);

			}

		}

		printf("%s\n", ((result) ? "happy": "sad"));
 
		arr.clear(); memset(visit, false, sizeof(visit));

	}

	return 0;

}