#include <bits/stdc++.h>

#define MAX 9

int Key[MAX], check[MAX];
std::vector<int> vec;

int main() {

	int sum = 0;

	for (int i = 0; i < MAX; i++)
		scanf("%d", Key + i), sum += Key[i];

	for (int i = 0; i < MAX; i++) {

		memset(check, true, sizeof(check));

		for (int j = i + 1; j < MAX; j++) {

			int result = sum - Key[i] - Key[j];

			if (result == 100) {

				check[i] = check[j] = false;

				for (int i = 0; i < MAX; i++)
					if (check[i])vec.push_back(Key[i]);

				sort(vec.begin(), vec.end());

				for (auto num : vec)
					printf("%d\n", num);

				exit(0);

			}

		}

	}

	return 0;

}