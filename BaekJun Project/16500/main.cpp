#include <iostream>
#include <string>
#include <algorithm>

#define MAX 101

std::string text;

std::string a[MAX];

bool dp[MAX];

bool isMatch(int w, std::string t) {

	int size = std::min(w + t.size(), text.size());

	for (int i = w; i < size; i++) {

		if (text[i] != t[i - w]) return false;

	}

	return true;

}

int main() {

	std::cin >> text;
	
	int n; std::cin >> n;

	for (int i = 0; i < n; i++) std::cin >> a[i];

	int size = text.size();
	int k = 0;

	dp[size] = 1;

	for (int i = size - 1; i >= 0; i--) {

		for (int j = 0; j <= n; j++) {

			if (text.find(a[j], i) == i && dp[i + a[j].size()]) {

				dp[i] = true;
				break;

			}
			else dp[i] = false;

		}

	}

	std::cout << dp[0] << "\n";

	return 0;

}