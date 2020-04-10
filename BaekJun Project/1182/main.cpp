#include <iostream>
#include <vector>

std::vector<int> arr;

int n, s, result;

void search(int num, int sum) {

	sum += arr[num];

	if (sum == s) result++;

	for (int i = num+1; i < n; i++)
		search(i, sum);

}

int main() {

	std::cin >> n >> s;
	for (int i = 0; i < n; i++) {

		int a; std::cin >> a;
		arr.push_back(a);

	}
		
	for (int i = 0; i < n; i++)
		search(i, 0);

	std::cout << result << "\n";

	return 0;

}