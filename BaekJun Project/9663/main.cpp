#include <bits/stdc++.h>

using namespace std;

int col[16]; // col[x] = y x«‡ yø≠
int n, num, cnt;

bool isGood(int x) {

	int k = 1;
	bool flag = true;

	while (k < x && flag) {

		if (col[x] == col[k] || abs(col[x] - col[k]) == abs(x - k))
			flag = false;

		k++;

	}

	return flag;

}

void dfs(int x) {

	if (isGood(x)) {

		if (x == n)
			cnt++;
		else {

			for (int j = 1; j <= n; j++) {

				col[x + 1] = j;
				dfs(x + 1);

			}

		}

	}

}

int main() {

	scanf("%d", &n);

	dfs(0);

	printf("%d\n", cnt);

	return 0;

}