#include <bits/stdc++.h>

using namespace std;

int n;
int a, b;

//i크기의 조각 크기를 만들 수 있는 경우의수
int dp1[1000001], dp2[1000001];

vector<int> arr1, arr2;
vector<int> sum1, sum2;

int main() {

	cin >> n;
	cin >> a >> b;
	
	arr1.resize(a + 1), arr2.resize(b + 1);
	sum1.resize(a + 1), sum2.resize(b + 1);
	for (int i = 1; i <= a; i++) cin >> arr1[i], sum1[i] = sum1[i - 1] + arr1[i];
	for (int i = 1; i <= b; i++) cin >> arr2[i], sum2[i] = sum2[i - 1] + arr2[i];

	dp1[0] = dp2[0] = 1;
	dp1[sum1[a]]++, dp2[sum2[b]]++;

	function<int(int, int)> GetSum1 = [&](int s, int e) -> int {

		if (s <= e) return sum1[e] - sum1[s - 1];
		return sum1[a] - sum1[s - 1] + sum1[e];

	};

	function<int(int, int)> GetSum2 = [&](int s, int e) -> int {

		if (s <= e) return sum2[e] - sum2[s - 1];
		return sum2[b] - sum2[s - 1] + sum2[e];

	};

	for (int i = 1; i <= a; i++)
		for (int j = 0; j < a - 1; j++) {

			int next = (i + j - 1) % a + 1;
			dp1[GetSum1(i, next)]++;

		}

	for (int i = 1; i <= b; i++)
		for (int j = 0; j < b - 1; j++) {

			int next = (i + j - 1) % b + 1;
			dp2[GetSum2(i, next)]++;

		}

	int ans = 0;

	for (int i = 0; i <= n; i++)
		ans += dp1[i] * dp2[n - i];

	cout << ans;

	return 0;

}