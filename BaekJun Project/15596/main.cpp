#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {

	long long result = 0;

	for (auto i : a) result += i;

	return result;

}