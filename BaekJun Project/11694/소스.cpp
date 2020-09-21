#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		//if (a == 1) a = 0;

		sum ^= a;
	}

	if (sum > 0) cout << "koosaga";
	else cout << "cubelover";
	return 0;
}