#include <bits/stdc++.h>

using namespace std;

struct Pair
{
	int pos, cnt;
};

struct cmp
{
	bool operator()(const Pair& p1, const Pair& p2)
	const {
		if (p1.pos != p2.pos) return p1.pos < p2.pos;
		return p1.cnt < p2.cnt;
	}
};

int n;
int arr[31];
map<Pair, bool, cmp> visit;
map<Pair, bool, cmp> dp;

bool solve(int pos, int cnt)
{
	if (cnt == 0) return true;
	if (pos == -1) return false;

	bool &ret = dp[{pos, cnt}];
	if (visit[{pos, cnt}]) return ret;

	visit[{pos, cnt}] = true;

	ret = max(ret, solve(pos-1, cnt));
	ret = max(ret, solve(pos-1, cnt + arr[pos]));
	ret = max(ret, solve(pos-1, cnt - arr[pos]));

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	solve(0, 0);

	int t; cin >> t;
	while (t--)
	{
		int a; cin >> a;
		cout << (solve(n-1, a) ? "Y" : "N") << " ";
	}

	return 0;
}