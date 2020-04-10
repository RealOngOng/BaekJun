//#include <iostream>
//#include <algorithm>
//
//#define MAX 100001
//
//int arr[MAX];
//int n;
//
//int result1, result2;
//
//long long func(int x, int y) {
//
//	if (x == y) return (long long) arr[x] * arr[x];
//
//	long long mid = (x + y) / 2;
//	long long result = std::max(func(x, mid), func(mid + 1, y));
//
//	int l = mid, r = mid + 1;
//
//	long long sum = arr[l] + arr[r], min = std::min(arr[l], arr[r]);
//
//	result = std::max(result, sum * min);
//
//	while (r - l <= y - x) {
//
//		if (r < y && (l == x || arr[l - 1] < arr[r + 1])) {
//
//			sum += arr[++r];
//			min = std::min(min, (long long) arr[r]);
//
//		}
//		else{
//
//			sum += arr[--l];
//			min = std::min(min, (long long) arr[l]);
//
//		}
//
//		result = std::max(result, sum * min);
//
//	}
//
//	return result;
//
//}
//
//int main() {
//
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++)
//		std::cin >> arr[i];
//
//	std::cout << func(0, n - 1) <<  "\n";
//
//	return 0;
////}