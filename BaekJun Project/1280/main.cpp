#include <iostream>

#define MOD 1000000007

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n; std::cin >> n;

	long long *dst = new long long[n + 1];
	int *arr = new int[n + 1];

	for (int i = 1; i <= n; i++)std::cin >> arr[i];

	long long score = 1;

	arr[0] = dst[0] = 0;

	for (int i = 1; i <= n - 1; i++)
		dst[i] = dst[i - 1] + (arr[i + 1] - arr[i]) * i, score = (score * dst[i]) % MOD;

	for (int i = 1; i <= n - 1; i++)
		std::cout << dst[i] << "\n";

	std::cout << score % MOD << "\n";

	return 0;

}