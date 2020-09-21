//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//
//#define MAX 1000001
//
//int arr[MAX];
//std::map<int, int> idx;
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(NULL), std::cin.tie(NULL);
//
//	int n; std::cin >> n;
//
//	std::set<int> pos;
//
//	for (int i = 0; i < n; i++) std::cin >> arr[i], pos.insert(arr[i]);
//
//	int w = 0;
//	for (auto itr = pos.begin(); itr != pos.end(); itr++) idx.insert({ *itr, w++ });
//
//	for (int i = 0; i < n; i++) std::cout << idx[arr[i]] << " ";
//
//	std::cout << "\n";
//
//	return 0;
//
//}