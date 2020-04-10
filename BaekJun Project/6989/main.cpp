#include <iostream>

#define MAX 151

int n, k;

int arr[MAX];

int dp[2][MAX];

int main() {

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::cin >> k;

	return 0;

}