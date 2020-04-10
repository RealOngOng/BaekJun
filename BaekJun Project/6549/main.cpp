//#include <iostream>
//#include <stack>
//#include <utility>
//#include <algorithm>
//
//typedef std::pair<int, int> Point;
//
//std::stack<Point> stk;
//
//int main() {
//
//	int n; std::cin >> n;
//
//	Point *p = new Point[n+2];
//
//	int len = 0;
//
//	for (int i = 1; i <= n + 1; i++) {
//
//		if (i == n + 1) p[i] = { 0, 0 };
//		else {
//
//			int a; std::cin >> a;
//			p[i] = { a, i };
//
//		}
//
//		while (!stk.empty() && stk.top().first > p[i].first) {
//
//			int h = stk.top().first;
//
//			stk.pop();
//
//			int w = i - stk.top().first - 1;
//
//			len = std::max(len, w * h);
//
//		}
//
//		stk.push(p[i]);
//
//	}
//
//	std::cout << len << "\n";
//
//	return 0;
//
//}