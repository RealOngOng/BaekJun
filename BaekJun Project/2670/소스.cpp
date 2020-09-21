#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<double> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	double ans = 0;
	double top = 1;
	for (int i = 0; i < n; i++)
	{
		top = max(arr[i], top * arr[i]);
		ans = max(ans, top);
	}
	
	cout << fixed;
	cout.precision(3);
	cout << ans;
	return 0;
}