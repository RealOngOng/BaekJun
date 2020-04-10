#include <iostream>
#include <algorithm>
#include <vector>

struct Q {

	int T = 0, N = 0;

};

#define MAX 11

std::vector<Q> arr;

int main() {

	int t, v;

	for (int i = 0; i < MAX; i++) {

		std::cin >> t >> v;
		arr.push_back({t, v});

	}

	std::sort(arr.begin(), arr.end(), 
			  [](const Q& q1, const Q& q2) -> bool {

		return q1.T < q2.T;

	});

	int p = 0;
	int sum = 0;

	for (Q q : arr)
	{

		sum += q.T;

		p += sum + 20 * q.N;

	}

	std::cout << p << "\n";

	return 0;

}