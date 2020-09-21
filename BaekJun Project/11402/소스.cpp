#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll n, r, c;

ll nCr[2010][2010];

ll mypow(ll a, ll b) {

	if (b == 0) return 1;
	ll p = mypow(a, b / 2);
	if (b % 2) return p * p * a;
	return p * p;

}

vector<ll> NBase(ll x) {

	ll pow = 0;

	while (true) {
		if (mypow(c, pow) > x) break;
		pow++;
	}

	pow--;
	vector<ll> ans;

	while (pow >= 0) {

		ll w = mypow(c, pow);
		ll k = x / w;
		ans.push_back(k);
		x = x % w;
		pow--;

	}

	return ans;

}

int main() {

	 cin >> n >> r >> c;

	 for (int i = 0; i < c; i++) {

		 nCr[i][0] = 1;
		 for (int j = 1; j <= i; j++)
			 nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % c;

	 }

	 vector<ll> nstr = NBase(n),
		 rstr = NBase(r);

	 int len = max(nstr.size(), rstr.size());
	 for (int i = 0; i < len - nstr.size(); i++)
		 nstr.insert(nstr.begin(), 0);
	 for (int i = 0; i < len - rstr.size(); i++)
		 rstr.insert(rstr.begin(), 0);

	 ll ans = 1;

	 for (int i = 0; i < len; i++) {

		 if (nstr[i] < rstr[i]) ans *= 0;
		 else
			ans = (ans * nCr[nstr[i]][rstr[i]] % c) % c;

	 }

	 cout << ans % c;

	return 0;

}