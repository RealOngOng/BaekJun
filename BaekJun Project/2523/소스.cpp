#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	string result;

	for (int j = 1; j <= n; j++) {

		for (int w = 0; w < j; w++) result += '*';

		result += '\n';

	}

	for (int j = n - 1; j > 0; j--) {

		for (int w = 0; w < j; w++) result += '*';

		result += '\n';

	}

	cout << result;

	return 0;

}