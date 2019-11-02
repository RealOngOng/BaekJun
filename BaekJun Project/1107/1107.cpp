#include <iostream>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

bool isIncludeNum(int _target, int _num) {

	do {

		if (_target % 10 == _num) return true;

	} while ((_target /= 10) != 0);

	return false;

}

int noList[10];

int main() {

	#pragma region Input

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) cin >> noList[i];

	#pragma endregion

	int min = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {

		bool _include = false;

		for (int w = 0; w < m; w++)
			if (isIncludeNum(i, noList[w])) { _include = true; break; }

		if (_include) continue;

		int count = to_string(i).length();

		count += abs(n - i);

		min = (min > count) ? count : min;

	}

	cout << min;

	return 0;

}