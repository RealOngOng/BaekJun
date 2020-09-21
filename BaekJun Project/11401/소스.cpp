#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll fact[4000001];

ll mypow(ll a, ll b) {

	if (b == 0) return 1;

	ll p = mypow(a, b / 2);
	if (b % 2 == 0) return (p * p) % MOD;
	else
		return ((p * p) % MOD * a) % MOD;

}

int main() {

	ll n, r;  cin >> n >> r;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 4000000; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	ll A = fact[n];
	ll B = (fact[r] * fact[n - r]) % MOD;

	cout << (A * mypow(B, MOD - 2)) % MOD;

	return 0;

}