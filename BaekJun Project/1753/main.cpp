//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//
//#define INF 987654321
//#define MAX 20001
//
//typedef long long ll;
//
//typedef struct Vertex{
//
//	int idx = 0;
//	ll num = INF;
//
//	std::vector<ll> adjust, weight;
//
//};
//
//struct comp {
//
//	bool operator()(const Vertex& v1, const Vertex& v2) {
//
//		return v1.num > v2.num;
//
//	}
//
//};
//
//Vertex vert[MAX];
//bool visit[MAX];
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL); std::cout.tie(NULL);
//
//	int v, e, k; std::cin >> v >> e >> k;
//
//	for (int i = 0; i < e; i++) {
//
//		int a, b, c; std::cin >> a >> b >> c;
//
//		vert[a].idx = a;
//
//		vert[a].adjust.push_back(b), vert[a].weight.push_back(c);
//
//	}
//
//	std::priority_queue<Vertex, std::vector<Vertex>, comp> queue;
//
//	vert[k].num = 0;
//	queue.push(vert[k]);
//
//	while (!queue.empty()) {
//
//		Vertex v = queue.top(); queue.pop();
//
//		if (visit[v.idx]) continue;
//
//		visit[v.idx] = true;
//
//		int count = v.adjust.size();
//
//		for (int i = 0; i < count; i++) {
//
//			int adj = vert[v.idx].adjust[i];
//
//			if (visit[adj]) continue;
//
//			if (vert[adj].num > v.num + v.weight[i]) {
//
//				vert[adj].num = std::min(vert[adj].num, v.num + v.weight[i]);
//				queue.push(vert[adj]);
//
//			}
//
//		}
//
//	}
//
//	for (int i = 1; i <= v; i++) {
//
//		if (vert[i].num == INF) std::cout << "INF\n";
//		else std::cout << vert[i].num << "\n";
//
//	}
//
//	return 0;
//
//}