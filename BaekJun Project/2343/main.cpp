#include <iostream>
#include <algorithm>

#define MAX 100001

int arr[MAX];
int n, k;

bool rayDisk(int max) {

	int sum = 0, count = 0;

	for (int i = 0; i < n; i++) {

		if(arr[i] > max) return false;

		if (sum + arr[i] > max) {

			count++;
			sum = 0;

		}

		sum += arr[i];

	}

	if (sum != 0) count++;
		
	return (count <= k);

}

int main() {

	std::cin >> n >> k;

	int low = 1, high = 0;

	for (int i = 0; i < n; i++) std::cin >> arr[i], high += arr[i];

	int result = 0;

	while (low <= high) {

		int mid = (low + high) * 0.5;

		bool isOk = rayDisk(mid);

		if (isOk) {

			result = mid;
			high = mid - 1;

		}
		else low = mid + 1;

	}

	std::cout << result << "\n";

	return 0;

}