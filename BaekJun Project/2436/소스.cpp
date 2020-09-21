#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> GetNum(ll x)
{
	vector<ll> arr;
	for (ll i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			arr.push_back(i);
			arr.push_back(x / i);
		}
	}

	vector<ll> ans;
	for (ll w : arr)
		if (w % n == 0)
			ans.push_back(w);

	return ans;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main()
{
	cin >> n >> m;

	vector<ll> num = GetNum(m);

	ll sum = LLONG_MAX;
	ll a = 0, b = 0;

	sort(num.begin(), num.end());
	for (ll i = 0; i < num.size(); i++)
	{
		for (ll j = i; j < num.size(); j++)
		{
			if (gcd(num[i], num[j]) == n && lcm(num[i], num[j]) == m)
			{
				if (sum > num[i] + num[j])
				{
					sum = num[i] + num[j];
					a = num[i], b = num[j];
				}
			}
		}
	}

	cout << a << " " << b;
	return 0;
}