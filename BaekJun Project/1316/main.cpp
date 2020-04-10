#include <iostream>
#include <map>
#include <string>

int group_count;

int main() {

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {

		std::map<int, bool> group;

		std::string str;
		std::cin >> str;

		bool isGroupWord = true;

		int length = str.length() - 1;

		for (int i = 0; i < length; i++) {

			if (str[i] != str[i+1]) {

				if (group[str[i + 1]]) {

					isGroupWord = false;
					break;

				}

			}

			group[str[i]] = true;

		}

		if (isGroupWord) group_count++;

	}

	std::cout << group_count << "\n";

	return 0;

}