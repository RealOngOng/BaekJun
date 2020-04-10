#include <iostream>
#include <algorithm>

#define MAX 1001

int arr[MAX];

int main() {

	int n, l;
	std::cin >> n >> l;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	std::sort(arr, arr + n);

	int a = arr[0];
	int result = 1;

	for (int i = 0; i < n; i++)
		if (a + (l - 1) < arr[i]) a = arr[i], result++;

	std::cout << result << "\n";

	return 0;

}