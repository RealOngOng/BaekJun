#include <bits/stdc++.h>

using namespace std;

int dp[1500001];
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int t, n; cin >> t >> n;

		int m1, m2;
		m1 = m2 = 1;

		int ans = 0;
		do
		{
			int temp = m1;
			m1 = m2;
			m2 = (temp + m2) % n;
			ans++;
		} while (!(m1 == 1 && m2 == 1));
		
		cout << t << " " << ans << "\n";
	}
	return 0;
}