#include <iostream>
#include <algorithm>

#define MAX 100001

int ldp[MAX], rdp[MAX], arr[MAX];

int main() {

	int n; std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> arr[i];

	ldp[0] = arr[0], rdp[n - 1] = arr[n - 1];

	int max = arr[0];

	for (int i = 1; i < n; i++)
		ldp[i] = std::max(arr[i], ldp[i - 1] + arr[i]),
		max = std::max(max, ldp[i]);

	for (int i = n - 2; i >= 0; i--)
		rdp[i] = std::max(arr[i], rdp[i + 1] + arr[i]);

	if (n > 1) {

		for (int i = 0; i < n; i++)
			max = std::max(max, ldp[i - 1] + rdp[i + 1]);

	}

	std::cout << max << '\n';
		
	return 0;

}