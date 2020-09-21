#include <bits/stdc++.h>

using namespace std;
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int s; cin >> s;
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b; cin >> a >> b;
			s += a * b;
		}
		cout << s << "\n";
	}
	return 0;
}