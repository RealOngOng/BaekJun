#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

typedef struct BigInteger {

	std::string num;

	void operator=(BigInteger bi) {

		num = bi.num;

	}
	void operator=(std::string str) {

		num = str;

	}
	bool operator<(BigInteger bi) {

		int sz1 = num.length(), sz2 = bi.num.length();

		if (sz1 != sz2) return (sz1 < sz2);

		bool min = false;

		for (int i = 0; i < sz1; i++) {

			int n1 = num[i] - '0', n2 = bi.num[i] - '0';

			if (n1 == n2) continue;

			min = (n1 < n2);
			break;

		}

		return min;

	}
	bool operator>(BigInteger bi) {

		int sz1 = num.length(), sz2 = bi.num.length();

		if (sz1 != sz2) return (sz1 > sz2);

		bool max = false;

		for (int i = 0; i < sz1; i++) {

			int n1 = num[i] - '0', n2 = bi.num[i] - '0';

			if (n1 == n2) continue;

			max = (n1 > n2);
			break;

		}

		return max;

	}

};

BigInteger mergeNum(BigInteger bi1, BigInteger bi2) {

	BigInteger bi;
	bi.num = bi1.num + bi2.num;

	return bi;

}

int main() {

	int k, n; std::cin >> k >> n;

	std::vector<BigInteger> arr(k);

	int max = 0;

	for (int i = 0; i < k; i++) {

		int input; std::cin >> input;

		arr[i] = std::to_string(input);

		max = std::max(max, input);

	}

	std::string max_str = std::to_string(max);

	for (int i = 0; i < n - k; i++) arr.push_back({ max_str });

	std::sort(arr.begin(), arr.end(),
			  [](BigInteger c1, BigInteger c2) -> bool {

		BigInteger m1 = mergeNum(c1, c2),
			m2 = mergeNum(c2, c1);

		return (m1 > m2);

	});

	for (int i = 0; i < n; i++)
		std::cout << arr[i].num;

	std::cout << "\n";

	return 0;

}