#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> arr;

struct Schedule {

	int day = 0,
		score = 0;

};

std::vector<Schedule> sch;

int main() {

	int n;
	std::cin >> n;

	arr.resize(1001);

	for (int i = 0; i < n; i++) {

		int d, w;

		std::cin >> d >> w;

		sch.push_back({d, w});

	}

	std::sort(sch.begin(), sch.end(),
			  [](const Schedule& sch1, const Schedule& sch2) -> bool {

		return sch1.score > sch2.score;

	});

	for (int i = 0; i < n; i++) {

		int day = sch[i].day;

		while (arr[day] != 0) {

			if (day < 0) break;
			day--;

		}

		if (day <= 0) continue;

		arr[day] = sch[i].score;

	}

	int result = 0;

	for (int i = 0; i < arr.size(); i++)
		result += arr[i];

	std::cout << result << "\n";

}