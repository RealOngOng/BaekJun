//#include <iostream>
//#include <utility>
//#include <vector>
//#include <algorithm>
//#include <limits.h>
//
//typedef std::pair<int, int> Vector2;
//
//typedef struct Box {
//
//	Vector2 pos1, pos2;
//
//	bool isCollision(Vector2 pos) {
//
//		return !(pos.first < pos1.first || pos.first > pos2.first 
//				|| pos.second < pos1.second || pos.second > pos2.second);
//
//	}
//
//};
//
////true 블랙, false 화이트
//typedef std::pair<Box, bool> Area;
//
//std::vector<Area> field;
//
//void PrintArea(Area area) {
//
//	std::cout << "(" << area.first.pos1.first << ", " << area.first.pos1.second << ") - "
//		<< " (" << area.first.pos2.first << ", " << area.first.pos2.second << ") "
//		<< ((area.second) ? "black" : "white") << "\n";
//
//}
//int GetArea(Area area) {
//
//	return (area.first.pos2.first - area.first.pos1.first) * (area.first.pos2.second - area.first.pos1.second);
//
//}
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL);
//
//	int a, b; std::cin >> a >> b;
//
//	Box all; all.pos1 = { 0, 0 }; all.pos2 = { a, b };
//
//	field.push_back({ all, false });
//
//	int n; std::cin >> n;
//	for (int i = 0; i < n; i++) {
//
//		int x, y; std::cin >> x >> y;
//
//		Vector2 target;
//		target.first = x, target.second = y;
//
//		Area includeArea;
//
//		int count = field.size();
//
//		std::vector<Area>::iterator itr;
//
//		for (itr = field.begin(); itr != field.end(); itr++) {
//
//			if ((*itr).first.isCollision(target)) {
//
//				includeArea = *itr;
//				field.erase(itr);
//				break;
//
//			}
//
//		}
//
//		// includeArea field에서 지우기
//
//		Vector2 includeVec1 = includeArea.first.pos1,
//			includeVec2 = includeArea.first.pos2;
//		
//		Area a1, a2;
//		Box a1_box, a2_box;
//
//		//화이트
//		if (!includeArea.second) {
//
//			a1_box.pos1 = includeVec1;
//			a1_box.pos2 = { includeVec2.first, target.second };
//
//			a2_box.pos1 = { includeVec1.first, target.second };
//			a2_box.pos2 = includeVec2;
//
//			a1.first = a1_box, a2.first = a2_box;
//
//			a1.second = a2.second = !includeArea.second;
//
//			field.push_back(a1), field.push_back(a2);
//			
//		}
//		//블랙
//		else {
//
//			a1_box.pos1 = includeVec1;
//			a1_box.pos2 = { target.first, includeVec2.second };
//
//			a2_box.pos1 = { target.first, includeVec1.second };
//			a2_box.pos2 = includeVec2;
//
//			a1.first = a1_box, a2.first = a2_box;
//
//			a1.second = a2.second = !includeArea.second;
//
//			field.push_back(a1), field.push_back(a2);
//
//		}
//
//	}
//
//	int max = -INT_MAX, min = INT_MAX;
//
//	int count = field.size();
//	for (int i = 0; i < count; i++) {
//
//		PrintArea(field[i]);
//
//		int e = GetArea(field[i]);
//
//		if (e < min) min = e;
//		if (e > max) max = e;
//
//	}
//
//	std::cout << max << " " << min << "\n";
//
//	return 0;
//
//}
