#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int dp[16][1 << 16]; //i 마을에 있을 때 j 마을들을 방문했을 때

int adj[16][16];

int n;

int solve(int num, int visit) {

	int &ret = dp[num][visit];

	if (ret != -1) return ret;

	if (visit == (1 << n) - 1) {

		if (adj[num][0] == 0) return INF;
		
		return adj[num][0];

	}

	ret = INF;
	for (int i = 0; i < n; i++) {

		if ((visit & (1 << i))) continue;
		if (adj[num][i] == 0) continue;

		ret = min(ret, solve(i, visit | (1 << i)) + adj[num][i]);

	}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);

	printf("%d\n", solve(0, 1));

	return 0;

}