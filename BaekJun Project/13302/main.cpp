#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int dp[101][101];
bool no[101];

int n, k;

int solve(int day, int coupon) {

	if (day > n) return 0;

	int &d = dp[day][coupon];

	if (d != INF) return d;
	if (no[day]) return d = solve(day + 1, coupon);

	d = min(d, solve(day + 1, coupon) + 10000);
	d = min(d, solve(day + 3, coupon + 1) + 25000);
	d = min(d, solve(day + 5, coupon + 2) + 37000);

	if (coupon >= 3) d = min(d, solve(day + 1, coupon - 3));

	return d;

}

int main() {

	scanf("%d %d", &n, &k);

	while (k--) { int a; scanf("%d", &a); no[a] = true; }

	fill(&dp[0][0], &dp[0][0] + 101 * 101, INF);

	cout << solve(1, 0) << "\n";

	return 0;

}