#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
string str[16];
//k로 나눈 나머지
int arr[16];
int len[16];
int pw[100];
//k로 나눈 나머지, 사용 상태
ll dp[101][1 << 15 + 1];

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else
		return gcd(b, a % b);
}

ll solve(int mod, int state)
{
	if(state == ((1 << n) - 1))
		return (mod == 0 ? 1 : 0);

	ll &ret = dp[mod][state];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (state & (1 << i)) continue;
		ret += solve(((mod * pw[len[i]]) % k + arr[i]) % k, state | (1 << i));
	}

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		len[i] = str[i].size();

		int &sum = arr[i];
		for (char c : str[i])
		{
			sum *= 10; sum %= k;
			sum += c - '0'; sum %= k;
		}
	}

	pw[0] = 1 % k;
	for (int i = 1; i <= 100; i++)
		pw[i] = pw[i - 1] * 10 % k;

	memset(dp, -1, sizeof(dp));
	
	ll v = solve(0, 0);
	if (v == 0)
	{
		cout << "0/1\n";
		return 0;
	}

	ll sum = 1;
	for (int i = n; i >= 1; i--)
		sum = sum * i;

	ll g = gcd(v, sum);

	cout << v / g << "/" << sum / g;
	return 0;
}