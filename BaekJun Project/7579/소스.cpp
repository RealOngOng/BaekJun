#include <bits/stdc++.h>

using namespace std;

int n, k;
int m[101], c[101];

//i코스트를 얻는 데 최대 메모리값
int dp[10001];

int main() {

	memset(dp, 0, sizeof(dp));

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> m[i];

	int sum = 0;

	for (int i = 0; i < n; i++)
		cin >> c[i], sum += c[i];

	for (int i = 0; i < n; i++) {

		for (int j = sum; j >= c[i]; j--)
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]);

	}

	int i = 0;
	for (i = 0; i < sum, dp[i] < k; i++);
	cout << i << endl;

	return 0;

}