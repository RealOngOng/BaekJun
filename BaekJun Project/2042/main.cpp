#include <iostream>
#include <algorithm>

int n, m, k;
long long *arr, *sum;

long long arr_sum(int a) {

	long long result = 0;

	while (a > 0) {

		result += sum[a];
		a -= (a & -a);

	}
	
	return result;

}

void arr_update(int a, long long b) {

	while (a <= n) {

		sum[a] += b;
		a += (a & -a);

	}

}

int main() {

	std::cin >> n >> m >> k;

	arr = new long long[n + 1];
	sum = new long long[n + 1];

	std::fill(sum, sum + n + 1, 0);

	for (int i = 1; i <= n; i++) {

		std::cin >> arr[i];
		arr_update(i, arr[i]);

	}

	for (int i = 1; i <= m + k; i++) {

		int w;
		long long a, b; std::cin >> w >> a >> b;

		if (w == 1) {

			arr_update(a, (long long) (b - arr[a]));
			arr[a] = b;

		}
		
		if (w == 2) std::cout << arr_sum(b) - arr_sum(a - 1) << "\n";

	}

	return 0;

}