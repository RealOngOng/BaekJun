#include <iostream>
#include <list>

#define MAX 9

int Key[MAX], check[MAX];
std::list<int> _;

__inline void TrueCheck() { for (int i = 0; i < MAX; i++) check[i] = true; }

int main() {

	int sum = 0;

	for (int i = 0; i < MAX; i++)
		std::cin >> Key[i], sum += Key[i];

	for (int i = 0; i < MAX; i++) {

		TrueCheck();

		for (int j = i + 1; j < MAX; j++) {

			int result = sum - Key[i] - Key[j];

			if (result == 100) {

				check[i] = check[j] = false;
				goto exit;

			}

		}

	}

	exit:

	for (int i = 0; i < MAX; i++)
		if (check[i])_.push_back(Key[i]);

	_.sort();

	for (auto num : _) std::cout << num << "\n";

	return 0;

}