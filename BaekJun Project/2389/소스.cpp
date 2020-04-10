//#include <iostream>
//#include <math.h>
//
//#define MAX 101
//
//typedef struct Vector2 {
//
//	double x, y;
//
//};
//
//Vector2 vert[MAX];
//
//double distance(Vector2 vec) { return vec.x * vec.x + vec.y * vec.y; }
//
//int main() {
//
//	std::cin.precision(11);
//
//	Vector2 center = {0, 0};
//
//	int n; std::cin >> n;
//	for (int i = 0; i < n; i++) {
//
//		double x, y; std::cin >> x >> y;
//		vert[i] = { x, y };
//
//		center.x += x, center.y += y;
//
//	}
//
//	center.x /=  n, center.y /= n;
//
//	double ratio = 0.1;
//	double maxDst = 0;
//
//	for (int i = 0; i < 30000; i++) {
//
//		int maxNum = 0;
//		maxDst = 0;
//		
//		for (int j = 0; j < n; j++) {
//
//			double dst = distance({ center.x - vert[j].x, center.y - vert[j].y});
//
//			if (maxDst < dst) {
//
//				maxNum = j;
//				maxDst = dst;
//
//			}
//
//		}
//
//		//std::cout << vert[maxNum].x - center.x << ", " << vert[maxNum].y - center.y << "\n";
//
//		center.x += (vert[maxNum].x - center.x) * ratio;
//		center.y += (vert[maxNum].y - center.y) * ratio;
//		ratio *= 0.999;
//
//	}
//
//	std::cout << center.x << " " << center.y << " " << std::sqrt(maxDst);
//
//	return 0;
//
//}
