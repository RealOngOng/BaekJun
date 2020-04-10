#include <iostream>

#define MAX 100001

int n, m;
int arr[MAX];

bool isOk(int max) {

	int count = 1, sum = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] > max) return false;

		sum += arr[i];

		if (sum > max) {

			count++;
			sum = arr[i];

		}

	}

	return (count <= m);

}

int main() {

	std::cin >> n >> m;

	int low = 0, high = 0;

	for (int i = 0; i < n; i++)std::cin >> arr[i], high += arr[i];

	int result = 0;

	while (low + 1 < high) {

		int mid = (low + high) * 0.5;

		if (isOk(mid)) {

			result = mid;
			high = mid;

		}
		else
			low = mid;

	}

	std::cout << result << "\n";

	return 0;

}