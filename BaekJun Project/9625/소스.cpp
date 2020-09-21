#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll a = 1, b = 0;

	ll k; cin >> k;

	for (int i = 0; i < k; i++)
	{
		ll ta = 0, tb = 0;

		ta += -a;
		tb += a;

		ta += b;
		tb += b;

		a += ta;
		b += tb - b;
	}

	cout << a << " " << b;
	return 0;
}