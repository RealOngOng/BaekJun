#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <limits.h>
#include <queue>

#define MAX 2100000

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define INF INT_MAX

typedef long long ll;

typedef struct Vector2 {

	int x, y;

	Vector2 operator+(Vector2 vec) { return { x + vec.x, y + vec.y }; }
	Vector2 operator-(Vector2 vec) { return { x + vec.x, y + vec.y }; }
	Vector2 operator*(int ratio) { return { x * ratio, y * ratio }; }

	bool operator==(Vector2 vec) { return ((x == vec.x) && (y == vec.y)); }

};

//정점
typedef struct Vertex {

	Vector2 pos;

	ll num = INF, a = 0;

	ll weight[4] = {INF, INF, INF, INF};

};

//상가
typedef struct Area {

	Vector2 pos1, pos2;

	ll cost;

};

//우선 순위 큐 정렬 기준
struct comp {
	bool operator()(const Vertex &a, const Vertex &b)
	{
		return a.a > b.a;
	}
};

Vector2 dv[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

Area area[1002];

Vertex vert[2002][2002];
bool visit[2002][2002];
Vector2 start, end;

std::map<int, int> xidx, yidx;
std::vector<ll> xpos, ypos;

int xpos_size, ypos_size;

//가중치 설정
void SetNode(Vector2 pos, int dir, ll value) {

	Vector2 sub = pos + dv[dir];

	if (sub.x < 0 || sub.y < 0 || sub.x >= xpos_size || sub.y >= ypos_size) {

		vert[pos.x][pos.y].weight[dir] = -1;
		return;

	}

	vert[pos.x][pos.y].pos = pos;
	vert[pos.x][pos.y].weight[dir] = (std::abs(xpos[pos.x] - xpos[sub.x]) + std::abs(ypos[pos.y] - ypos[sub.y])) * value;

}

//휴리스틱
ll H(Vector2 idx) { return std::abs(xpos[idx.x] - end.x) + std::abs(ypos[idx.y] - end.y); }

int main() {

	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL); std::cin.tie(NULL);

	std::cin >> start.x >> start.y >> end.x >> end.y;
	
	//중복된 좌표를 제외하여 x, y좌표 따로 정렬
	std::set<int> xorder, yorder;

	xorder.insert(start.x), xorder.insert(end.x);
	yorder.insert(start.y), yorder.insert(end.y);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {

		int x1, y1, x2, y2, cost;

		std::cin >> x1 >> y1 >> x2 >> y2 >> cost;

		area[i] = { {x1, y1}, {x2, y2}, cost };

		xorder.insert(x1), xorder.insert(x2);
		yorder.insert(y1), yorder.insert(y2);

	}

	xpos.resize(2002), ypos.resize(2002);

	int size_x = 0, size_y = 0;

	for (auto itr = xorder.begin(); itr != xorder.end(); itr++) {

		xpos[size_x] = *itr;
		xidx[*itr] = size_x++;

	}

	for (auto itr = yorder.begin(); itr != yorder.end(); itr++) {

		ypos[size_y] = *itr;
		yidx[*itr] = size_y++;

	}

	xpos_size = xpos.size(), ypos_size = ypos.size();

	//만들어진 정점에 대해 기본 가중치 10을 설정
	for (int x = 0; x < size_x; x++)
		for (int y = 0; y < size_y; y++)
			for (int i = 0; i < 4; i++)
				SetNode({ x, y }, i, 10);

	//각 상가에 대해 가중치 설정
	for (int i = 0; i < n; i++) {

		int start_x = xidx[area[i].pos1.x],
			start_y = yidx[area[i].pos1.y];

		int end_x = xidx[area[i].pos2.x],
			end_y = yidx[area[i].pos2.y];

		for (int x = start_x; x < end_x; x++)
			for (int y = start_y; y < end_y; y++) {

				if (x != start_x) {

					SetNode({ x, y }, UP, area[i].cost);
					SetNode({ x, y + 1 }, DOWN, area[i].cost);

				}

				if (y != start_y) {

					SetNode({ x, y }, RIGHT, area[i].cost);
					SetNode({ x + 1, y }, LEFT, area[i].cost);

				}

			}

	}

	//A*
	std::priority_queue<Vertex, std::vector<Vertex>, comp> q;

	vert[xidx[start.x]][yidx[start.y]].num = 0;

	q.push(vert[xidx[start.x]][yidx[start.y]]);

	while (!q.empty()) {

		Vertex v = q.top(); q.pop();

		if (visit[v.pos.x][v.pos.y]) continue;

		visit[v.pos.x][v.pos.y] = true;

		for (int i = 0; i < 4; i++) {

			Vector2 pos = v.pos + dv[i];

			if (v.weight[i] == -1) continue;
			if (visit[pos.x][pos.y]) continue;

			Vertex &next = vert[pos.x][pos.y];

			if (next.num > v.num + v.weight[i]) {

				next.num = std::min(next.num, v.num + v.weight[i]);
				next.a = next.num + H(pos);

				q.push(next);

			}

		}

	}

	std::cout << vert[xidx[end.x]][yidx[end.y]].num << "\n";

	return 0;

}