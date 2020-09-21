#include <bits/stdc++.h>

using namespace std;

int a, b, c;
bool dp[301];

void solve(int x)
{
	if (x > 300) return;

	if (dp[x]) return;

	dp[x] = true;
	solve(x + a);
	solve(x + b);
	solve(x + c);
}

int main()
{
	int n;
	cin >> a >> b >> c >> n;
	solve(0);

	cout << dp[n];
	return 0;
}