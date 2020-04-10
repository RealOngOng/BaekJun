#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX 51
#define INF 100000000

int rdp[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];

int rFunc(int n, int m) {

	if (n == 0 || m == 0) return INF;

	if (n < m) std::swap(n, m);

	if (n % m == 0) return n / m;

	int &ret = rdp[n][m];

	if (ret != -1) return ret;

	ret = INF;

	if (n > 3 * m) ret = std::min(ret, rFunc(n - m, m) + 1);
	else {

		for (int q = 1; q <= n * 0.5; q++) ret = std::min(ret, rFunc(q, m) + rFunc(n - q, m));

		for (int q = 1; q <= m * 0.5; q++) ret = std::min(ret, rFunc(n, q) + rFunc(n, m - q));

	}

	return ret;

}

int func(int h1, int w1, int h2, int w2) {

	int &ret = dp[h1][w1][h2][w2];

	if (ret != -1) return ret;

	int h3 = h1 - h2;
	int w3 = w1 - w2;

	ret = INF;

	for (int q = 1; q < h1; q++) {

		if (q < h2) ret = std::min(ret, rFunc(q, w3) + func(h1 - q, w1, h2 - q, w2));
		else if (q == h2) ret = std::min(ret, rFunc(q, w3) + rFunc(h1 - q, w1));
		else ret = std::min(ret, rFunc(h1 - q, w1) + func(q, w1, h2, w2)); 

	}

	for (int q = 1; q < w1; q++) {

		if (q < w3) ret = std::min(ret, rFunc(h1, q) + func(h1, w1 - q, h2, w2));
		else if (q == w3) ret = std::min(ret, rFunc(h1, q) + rFunc(h3, w2));
		else ret = std::min(ret, rFunc(h3, w1 - q) + func(h1, q, h2, q - w3));

	}

	return ret;

}

int main() {

	memset(rdp, -1, sizeof rdp);
	memset(dp, -1, sizeof dp);

	int a, b, c, d; std::cin >> a >> b >> c >> d;

	std::cout << func(a, b, c, d) << "\n";

	return 0;

}