//#include <iostream>
//#include <string>
//#include <math.h>
//
//bool isClap1(int num) {
//
//	if (num % 3 == 0) return true;
//
//	if (std::to_string(num).find('3') != std::string::npos) return true;
//	if (std::to_string(num).find('6') != std::string::npos) return true;
//	if (std::to_string(num).find('9') != std::string::npos) return true;
//
//	return false;
//
//}
//
//int main() {
//
//	while (true) {
//
//		int a, b; std::cin >> a >> b;
//
//		int sum_1 = 0;
//
//		for (int i = a; i <= b; i++) {
//
//			sum_1 += isClap1(i);
//
//		}
//
//		std::cout << a << "~" << b << " : " << sum_1 << "\n";
//
//	}
//
//	return 0;
//
//}