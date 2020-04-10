#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

long long Area;

std::vector<std::pair<long long, int>> cubes;

int main() {

	int a, b, c;
	std::cin >> a >> b >> c;
	
	Area = a * b * c;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {

		int q, w;

		std::cin >> q >> w;

		cubes.push_back({powl(powl(2, q), 3), w});

	}

	std::sort(cubes.begin(), cubes.end(), std::greater<std::pair<long long, int>>());

	int count = cubes.size();

	long long result = 0;

	for (int i = 0; i < count; i++) {

		for (int j = 0; j < cubes[i].second; j++) {

			if (cubes[i].first > Area) break;

			Area -= cubes[i].first;
			result++;

		}

	}

	if(Area > 0) std::cout << "-1\n";
	else std::cout << result << "\n";

	return 0;

}