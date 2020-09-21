#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	n %= 7;

	if (n == 1 || n == 3) cout << "CY";
	else cout << "SK";
	return 0;
}