#include <bits/stdc++.h>

using namespace std;

int t, w;

bool arr[2][1001];
int dp[2][1001][30]; //[나무][시간][움직인 횟수]

int solve(int num, int time, int move) {

	if (t == time) return 0;
	if (dp[num][time][move] != -1) return dp[num][time][move];

	int &ret = dp[num][time][move];

	int a1 = 0, a2 = 0;

	if (arr[num][time]) {

		if (move < w)
			a1 = max(solve(num, time + 1, move) + 1, solve((num + 1) % 2, time + 1, move + 1));
		else
			a2 = solve(num, time + 1, move) + 1;

		ret = max(a1, a2);

	}
	else {

		if (move < w)
			a1 = max(solve(num, time + 1, move), solve((num + 1) % 2, time + 1, move + 1) + 1);
		else
			a2 = solve(num, time + 1, move);

		ret = max(a1, a2);

	}

	return ret;

}

int main() {

	scanf("%d %d", &t, &w);

	for (int i = 0; i < t; i++) {

		int a; scanf("%d", &a);
		arr[a - 1][i] = true;

	}

	memset(dp, -1, sizeof(dp));

	//for (int q = 0; q < 2; q++) {

	//	for (int j = 0; j < w; j++) {

	//		for (int i = 0; i < t; i++)
	//			printf("%d ", dp[q][i][j]);

	//		printf("\n");

	//	}

	//	printf("\n");

	//}

	printf("%d\n", solve(0, 0, 0));

	return 0;

}