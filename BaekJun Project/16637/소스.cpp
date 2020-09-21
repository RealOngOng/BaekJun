#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll cnt = -1e10;

ll func(ll a, ll b, char oper) {

	if (oper == '+') return a + b;
	if (oper == '-') return a - b;
	if (oper == '*') return a * b;

	return 0;

}

ll cal(vector<ll> num, vector<char> oper) {

	ll top = num[0];

	for (int i = 0; i < oper.size(); i++)
		top = func(top, num[i + 1], oper[i]);

	return top;

}

void dfs(int pos, vector<ll> num, vector<char> oper) {

	if (pos >= n / 2) {

		cnt = max(cnt, cal(num, oper));
		return;

	}

	dfs(pos + 1, num, oper);

	num[pos] = func(num[pos], num[pos + 1], oper[pos]);
	num[pos + 1] = 0;
	oper[pos] = '+';

	dfs(pos + 2, num, oper);


}

int main() {

	cin >> n;
	string str; cin >> str;

	vector<ll> num;
	vector<char> oper;

	for (int i = 0; i < n; i++) {

		if (i % 2 == 0) num.push_back(str[i] - '0');
		else oper.push_back(str[i]);

	}

	dfs(0, num, oper);

	cout << cnt;

	return 0;

}