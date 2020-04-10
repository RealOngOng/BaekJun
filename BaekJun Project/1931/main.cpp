#include <iostream>
#include <algorithm>
#include <vector>

struct Plan {

	int start = 0, end = 0;

};

std::vector<Plan> arr;

int main() {

	int n; std::cin >> n;

	int end_time = 0;

	for (int i = 0; i < n; i++) {

		int start, end;
		std::cin >> start >> end;

		if (end >= end_time) end_time = end;

		Plan p = { start, end };

		arr.push_back(p);

	}

	std::sort(arr.begin(), arr.end(), 
	[](const Plan& p1, const Plan& p2) -> int {

		return (p1.end - p1.start) < (p2.end - p2.start);

	});

	std::sort(arr.begin(), arr.end(),
			  [](const Plan& p1, const Plan& p2) -> int {

		if (p1.end == p2.end) return p1.start < p2.start;

		return p1.end < p2.end;

	});

	int temp = 0;
	int result = 0;

	for (Plan p : arr) {

		if (temp <= p.start) {

			temp = p.end;
			result++;

		}

	}
		
	std::cout << result << "\n";

	return 0;

}