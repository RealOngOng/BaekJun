#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;

	int ans = 0;
	int block = 0;
	while (block <= n)
	{
		block += 2 * ans * ans + 2 * ans + 1;
		ans++;
	}

	cout << ans - 1;
	return 0;
}