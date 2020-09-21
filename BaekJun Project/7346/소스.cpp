#include <bits/stdc++.h>

using namespace std;

map<char, int> idx;
int c[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};
int dp[101][101][101];

int cost(char a, char b) { return c[idx[a]][idx[b]]; }

int main()
{
	char carr[] = { 'A', 'C', 'G', 'T', '*' };
	int num = 0;
	for (char c : carr)
		idx[c] = num++;

	int tc; cin >> tc;
	while (tc--)
	{
		int n;
		string a, b;
		cin >> n >> a >> n >> b;

		memset(dp, -1, sizeof(dp));

		function<int(int, int, int)> solve = [&](int pa, int pb, int k) -> int
		{
			if (pa == a.length() || pb == b.length())
			{
				int v = 0;
				for (int i = pb; i < a.length(); i++)
					v += cost(a[i], '*');
				for (int i = pa; i < b.length(); i++)
					v += cost(b[i], '*');

				return v;
			}

			int &ret = dp[pa][pb][k];
			if (ret != -1) return ret;

			ret = -0x3f3f3f3f;
			//위에 공백을 넣는 경우
			ret = max(ret, solve(pa, pb + 1, k + 1) + cost('*', b[pb]));
			//아래에 공백을 넣는 경우
			ret = max(ret, solve(pa + 1, pb, k + 1) + cost(a[pa], '*'));
			//둘다 공백을 넣는 경우
			if(pa != pb)
				ret = max(ret, solve(pa + 1, pb + 1, k + 1) + cost(a[pa], '*') + cost('*', b[pb]));
			//공백을 안 넣는 경우
			ret = max(ret, solve(pa + 1, pb + 1, k) + cost(a[pa], b[pb]));

			cout << pa << " " << pb << " " << ret << "\n";
			return ret;
		};

		cout << solve(0, 0, 0) << "\n";

	}
	return 0;
}