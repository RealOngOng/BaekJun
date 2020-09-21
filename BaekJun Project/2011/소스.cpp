#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000

//i�ڸ����� ������ �� �ִ�
int dp[5002];

int n;
string str;

int main() {

	cin >> str;
	n = str.length();

	str = " " + str;

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {

		if (str[i] != '0')
			dp[i] = dp[i - 1];

		if (i == 1) continue;

		int prev = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (10 <= prev && prev <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % MOD;

	}

	if (str == "0")
		cout << "0";
	else
		cout << dp[n];

	return 0;

}