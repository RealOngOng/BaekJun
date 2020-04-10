#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Study {

	int s = 0,
		t = 0;

};

std::vector<Study> arr;

int main() {

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {

		int s, t; std::cin >> s >> t;

		arr.push_back({s, t});

	}

	std::sort(arr.begin(), arr.end(), 
			  [](const Study& s1, const Study& s2) -> bool {

		return s1.s < s2.s;

	});

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int result = 0;

	for (Study s : arr) {

		if (pq.size() > 0 && s.s >= pq.top()) {

			pq.pop();
			pq.push(s.t);

		}
		else
			pq.push(s.t);

		if (result < pq.size()) result = pq.size();

	}

	std::cout << result << "\n";

	return 0;

}