#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n; cin >> n;
	n %= 7;

	if (n == 0 || n == 2) cout << "CY\n";
	else cout << "SK\n";
	return 0;
}