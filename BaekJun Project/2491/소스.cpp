#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int dp1[100001], dp2[100001];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans1 = 1, ans2 = 1;

	dp1[0] = dp2[0] = 1;
	for (int i = 1; i < n; i++)
		if (arr[i - 1] <= arr[i])
		{
			dp1[i] = dp1[i - 1] + 1;
			ans1 = max(ans1, dp1[i]);
		}
		else
			dp1[i] = 1;

	for (int i = 1; i < n; i++)
		if (arr[i - 1] >= arr[i])
		{
			dp2[i] = dp2[i - 1] + 1;
			ans2 = max(ans2, dp2[i]);
		}
		else
			dp2[i] = 1;

	cout << max(ans1, ans2);

	return 0;
}