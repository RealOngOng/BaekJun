#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int MinCrossNumber(int a, int b, int c, int d) {

	int arr[4] = { a, b, c, d };
	int m = 1e5;

	for (int i = 0; i < 4; i++) {

		string str;

		for (int j = 0; j < 4; j++)
			str += arr[(i + j) % 4] + '0';

		m = min(m, atoi(str.c_str()));

	}

	return m;

}

int main() {

	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++)
			for (int c = 1; c <= 9; c++)
				for (int d = 1; d <= 9; d++)
					vec.push_back(MinCrossNumber(a, b, c, d));

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);

	int idx = lower_bound(vec.begin(), vec.end(), MinCrossNumber(a, b, c, d)) - vec.begin();

	printf("%d\n", idx + 1);

	return 0;

}