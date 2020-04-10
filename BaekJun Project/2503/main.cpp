#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 1000

int check[MAX];

struct StrikeResult {

	std::vector<bool> isSt;
	std::string remains;
	int count = 0;

};

StrikeResult isStrike(std::string target, std::string to) {

	StrikeResult result;

	std::string temp = to;

	for (int i = 0; i < target.length(); i++) {

		if (target[i] == to[i])
			temp = temp.erase(i - result.count++, 1);

		result.isSt.push_back(target[i] == to[i]);

	}

	return result;

}

bool isBall(std::string target, char to) {

	return (target.find(to) >= 0 && target.find(to) != std::string::npos);

}

bool isillegalNumber(std::string target) {

	bool if1 = (target[0] == target[1] || target[1] == target[2] || target[0] == target[2]);

	int s_pos = target.find('0');

	bool if2 = (s_pos > 0 && s_pos != std::string::npos);

	return (if1 || if2);

}

int main() {

	int n;	
	std::cin >> n;

	std::fill(check, check + MAX, 0);

	int num, strike, ball;

	for (int i = 0; i < n; i++) {

		std::cin >> num >> strike >> ball;

		std::string num_s = std::to_string(num);

		for (int j = 100; j < MAX; j++) {

			std::string target = std::to_string(j);

			if (isillegalNumber(target)) continue;

			StrikeResult strResult = isStrike(target, num_s);

			int str = strResult.count;

			int b = 0;

			for (int w = 0; w < 3; w++) {

				if (strResult.isSt[w]) continue;

				if (isBall(target, num_s[w])) b++;

			}

			check[j] += (str == strike && b == ball);

		}

	}

	int result = 0;

	for (int i = 100; i < MAX; i++)
		if (check[i] == n) result++;

	std::cout << result << "\n";

	return 0;

}