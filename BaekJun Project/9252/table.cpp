#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1001

std::string lcs[MAX][MAX];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	std::string str1, str2;

	std::cin >> str1 >> str2;

	int t1 = str1.length(), t2 = str2.length();

	for (int i = 1; i <= t1; i++) {

		for (int j = 1; j <= t2; j++) {

			if (str1[i - 1] == str2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + str1[i - 1];
			else {

				if (lcs[i - 1][j].length() > lcs[i][j - 1].length())
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];

			}

		}

	}

	std::cout << lcs[t1][t2].length() << "\n" << lcs[t1][t2] << "\n";

	return 0;

}