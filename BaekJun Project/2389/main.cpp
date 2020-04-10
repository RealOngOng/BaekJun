//#include <iostream>
//#include <utility>
//#include <math.h>
//#include <limits.h>
//#include <algorithm>
//
//typedef std::pair<long double, long double> Vector2;
//
//Vector2 *vert;
//
//long double distance(Vector2 vec1, Vector2 vec2) {
//
//	long double sub_x = vec1.first - vec2.first,
//			  sub_y = vec1.second - vec2.second;
//
//	return sub_x * sub_x + sub_y * sub_y;
//
//}
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL); std::cout.tie(NULL);
//
//	std::cout.precision(4);
//
//	double n; std::cin >> n;
//
//	vert = new Vector2[(int)n + 1];
//
//	Vector2 centerPos;
//
//	for (int i = 0; i < n; i++) {
//
//		double x, y; std::cin >> x >> y;
//		vert[i] = { x, y };
//
//		centerPos.first += x;
//		centerPos.second += y;
//
//	}
//
//	centerPos.first /= n;
//	centerPos.second /= n;
//
//	long long max = -INT_MAX;
//	Vector2 max_vec;
//
//	std::sort(vert, vert + (int)n);
//
//	for (int i = 0; i < n; i++) {
//
//		long long d = distance(vert[i], centerPos);
//
//		if (d > max) {
//
//			max = d;
//			max_vec = vert[i];
//
//		}
//
//	}
//
//	std::sort(vert, vert + (int)n, 
//			  [](const Vector2& vec1, const Vector2& vec2) -> bool {
//		return (vec1.second < vec2.second);
//	});
//
//	for (int i = 0; i < n; i++) {
//
//		long long d = distance(vert[i], centerPos);
//
//
//		if (d > max) {
//
//			max = d;
//			max_vec = vert[i];
//
//		}
//
//	}
//
//	std::cout << centerPos.first << " " << centerPos.second 
//		<< " " << std::sqrt(distance(centerPos, max_vec)) << "\n";
//
//	return 0;
//
//}