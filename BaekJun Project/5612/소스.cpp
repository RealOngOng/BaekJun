#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m; scanf("%d %d", &n, &m);

	int result = m;
	int num = m;

	while (n--) {

		int in, out; scanf("%d %d", &in, &out);

		num += (in - out);

		if (num < 0) {

			printf("0\n");
			return 0;

		}

		result = max(result ,num);

	}

	printf("%d", result);

	return 0;

}