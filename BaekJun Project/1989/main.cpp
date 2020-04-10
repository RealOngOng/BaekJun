#include <iostream>
#include <algorithm>

#define MAX 100001

int arr[MAX];
int n;

int num1, num2;

long long result = 0;

long long func(int x, int y) {

	if (x == y) return arr[x] * arr[x];

	long long mid = (x + y) / 2;

	long long n1 = func(x, mid), n2 = func(mid + 1, y);

	if (n1 >= n2) {

		if (result != n1) num1 = x, num2 = mid;
		result = n1;

	}
	else {

		if (result != n2) num1 = mid + 1, num2 = y;
		result = n2;

	}

	int l = mid, r = mid + 1;

	long long sum = arr[l] + arr[r], min = std::min(arr[l], arr[r]);

	if (result <= sum * min) {

		if (result != sum * min)num1 = l, num2 = r;
		result = sum * min;

	}

	while (r - l <= y - x) {

		if (r < y && (l == x || arr[l - 1] < arr[r + 1])) {

			sum += arr[++r];
			min = std::min(min, (long long)arr[r]);

		}
		else {

			sum += arr[--l];
			min = std::min(min, (long long)arr[l]);

		}

		//result = std::max(result, sum * min);

		if (result <= sum * min) {

			if (result != sum * min)num1 = l, num2 = r;
			result = sum * min;

		}

	}

	return result;

}

int main() {

	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::cout << func(0, n - 1) << "\n";
	std::cout << num1 + 1 << " " << num2 + 1 << "\n";

	return 0;

}