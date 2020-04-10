//#include <iostream>
//#include <stdlib.h>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//#pragma region Struct
//
//typedef pair<int, int> Vector2;
//typedef pair<Vector2, Vector2> Block;
//
//__inline bool between(Vector2 _p, Vector2 _start, Vector2 _end) 
//{
//
//	return (_start.first <= _p.first && _p.first <= _end.second)
//		&& (_start.first <= _p.second && _p.second <= _end.second);
//
//}
//
//__inline float distance(Vector2 _p1, Vector2 _p2) {return (_p1.first - _p2.first) * (_p1.first - _p2.first) + (_p1.second - _p2.second) * (_p1.second - _p2.second);}
//
//__inline bool inBlock(Block _b, Vector2 _vec1, Vector2 _vec2)
//{
//
//	if ((_vec1.first == _b.first.first && _vec2.first == _b.first.first) ||
//		(_vec1.first == _b.second.first && _vec2.first == _b.second.first) ||
//		(_vec1.second == _b.first.second && _vec2.second == _b.first.second) ||
//		(_vec1.second == _b.second.second && _vec2.second == _b.second.second)) return false;
//
//	return between(_vec1, _b.first, _b.second) && between(_vec2, _b.first, _b.second);
//
//}
//
//#pragma endregion
//
//#pragma region Method
//
//Vector2 cinVector2();
//int H_Hueristic(Vector2);
//
//#pragma endregion
//
//Vector2 normalVector[4] = {
//	Vector2(0, 1),
//	Vector2(1, 0),
//	Vector2(-1, 0),
//	Vector2(0, -1)};
//
//Block* Blocks;
//int* BlockPrice;
//int BlockNum;
//
//Vector2 pos_start, pos_end;
//
//int Hueristic_G[8], Hueristic_H[8], route = 0;
//
//int main() {
//
//	#pragma region sync_false
//
//	ios::sync_with_stdio(false);
//
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	#pragma endregion
//
//	#pragma region input
//
//	pos_start = cinVector2(); pos_end = cinVector2();
//
//	cin >> BlockNum;
//
//	Blocks = new Block[BlockNum];
//	BlockPrice = new int[BlockNum];
//
//	Vector2 _vec1, _vec2;
//
//	int _price;
//	for (int i = 0; i < BlockNum; i++)
//	{
//
//		_vec1 = cinVector2(); _vec2 = cinVector2();
//
//		cin >> _price;
//
//		Blocks[i] = Block(_vec1, _vec2);
//		BlockPrice[i] = _price;
//
//	}
//
//	#pragma endregion
//
//	int Dir = 0, minScore;
//
//	Vector2 back = Vector2();
//
//	while (pos_start != pos_end) {
//
//		int _routeScore = 0;	
//		minScore = INT32_MAX;
//
//		for (int i = 0; i < 4; i++) {
//
//			Vector2 frontVec = Vector2(pos_start.first + normalVector[i].first, pos_start.second + normalVector[i].second);
//
//			if (frontVec.first < 0 || frontVec.second < 0 || frontVec == back) continue;
//
//			#pragma region Score_h
//
//			Hueristic_G[i] = distance(frontVec, pos_end);
//			Hueristic_H[i] = H_Hueristic(frontVec);
//
//			if (Hueristic_G[i] + Hueristic_H[i] < minScore ||
//				(Hueristic_G[i] + Hueristic_H[i] == minScore && Hueristic_G[i] < Hueristic_G[Dir]))
//			{
//
//				_routeScore = Hueristic_H[i];
//
//				Dir = i;
//				minScore = Hueristic_G[i] + Hueristic_H[i];
//
//			}
//
//			#pragma endregion
//
//		}
//
//		back = pos_start;
//
//		pos_start = Vector2(pos_start.first + normalVector[Dir].first, pos_start.second + normalVector[Dir].second);
//
//		route += _routeScore;
//
//	}
//
//	cout << route << endl;
//
//	return 0;
//
//}
//
//__inline Vector2 cinVector2()
//{
//
//	int _x, _y;
//	cin >> _x >> _y;
//
//	return Vector2(_x, _y);
//
//}
//
//__inline int H_Hueristic(Vector2 _vec1)
//{
//
//	int h = 10;
//
//	for (int i = 0; i < BlockNum; i++) {
//
//
//		if (inBlock(Blocks[i], pos_start, _vec1)) {
//
//			h = BlockPrice[i];
//			break;
//
//		}
//
//	}
//
//	return h;
//
//}