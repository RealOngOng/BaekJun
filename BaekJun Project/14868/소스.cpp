//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef struct Vector2 {
//
//	int x, y;
//
//};
//
//typedef struct bdata {
//
//	Vector2 pos;
//	int year;
//
//};
//
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//int n, k;
//
//int field[2001][2001];
//bool visit[2001][2001];
//vector<Vector2> origin;
//Vector2 start;
//
//bool isOut(Vector2 vec) { return (vec.x < 1 || vec.x > n || vec.y < 1 || vec.y > n); }
//bool func(int num) {
//
//	memset(visit, false, sizeof(visit));
//
//	int cnt = 0;
//
//	queue<Vector2> q;
//
//	q.push(start);
//	visit[start.x][start.y] = true;
//
//	while (!q.empty()) {
//
//		Vector2 top = q.front(); q.pop();
//
//		if (field[top.x][top.y] == 0)
//			cnt++;
//
//		for (int i = 0; i < 4; i++) {
//
//			Vector2 front = { top.x + dx[i], top.y + dy[i] };
//
//			if (isOut(front) || field[front.x][front.y] > num || visit[front.x][front.y]) continue;
//
//			visit[front.x][front.y] = true;
//			q.push(front);
//
//		}
//
//	}
//
//	return cnt == k;
//
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	memset(field, -1, sizeof(field));
//
//	cin >> n >> k;
//
//	queue<bdata> q;
//
//	for (int i = 0; i < k; i++) {
//
//		int a, b; cin >> a >> b;
//		origin.push_back({a, b});
//
//		field[a][b] = 0;
//		q.push({ {a, b}, 0 });
//
//	}
//
//	start = origin[0];
//
//	while (!q.empty()) {
//
//		bdata top = q.front(); q.pop();
//
//		for (int i = 0; i < 4; i++) {
//
//			Vector2 front = { top.pos.x + dx[i], top.pos.y + dy[i] };
//
//			if (isOut(front) || field[front.x][front.y] != -1) continue;
//
//			field[front.x][front.y] = top.year + 1;
//			q.push({front, top.year + 1});
//
//		}
//
//	}
//
//	int lo = 0, hi = 1000;
//
//	while (lo < hi) {
//
//		int mid = (lo + hi) / 2;
//
//		if (func(mid))
//			hi = mid;
//		else
//			lo = mid + 1;
//
//	}
//
//	cout << lo;
//
//	return 0;
//
//}