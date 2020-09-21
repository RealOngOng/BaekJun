//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//#define MAX 1000001
//
//std::vector<int> arr, vec;
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(NULL), std::cin.tie(NULL);
//
//	int n; std::cin >> n;
//
//	arr.resize(n), vec.resize(n);
//
//	for (int i = 0; i < n; i++) std::cin >> arr[i], vec[i] = arr[i];
//
//	std::sort(vec.begin(), vec.end());
//	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
//
//	for (int i = 0; i < n; i++)
//		std::cout << std::lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin() << " ";
//
//	std::cout << "\n";
//
//}