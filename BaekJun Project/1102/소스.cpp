#include <bits/stdc++.h>

using namespace std;

int dp[16][(1 << 16) + 1];// 고친 발전기 개수, 고친 발전기
int adj[16][16];

int n, p;

int solve(int count, int visit) {

	if (count == p) return 0;

	int &ret = dp[count][visit];

	if (ret != -1) return ret;

	ret = 987654321;
	for (int i = 0; i < n; i++) {

		if (!(visit & (1 << i))) continue;

		for (int j = 0; j < n; j++) {

			if ((visit & (1 << j))) continue;

			ret = min(ret, solve(count + 1, visit | (1 << j)) + adj[i][j]);

		}

	}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);

	int count = 0;

	int visit = 0;
	for (int i = 0; i < n; i++) {

		char c; scanf(" %c", &c);
		if (c == 'Y')
			visit += (1 << i), count++;

	}

	scanf("%d", &p);

	if (count >= p) {

		printf("0\n");
		return 0;

	}

	if (count == 0) printf("-1\n");
	else 
		printf("%d\n", solve(count, visit));


	return 0;

}