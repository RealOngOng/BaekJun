#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc; cin >> tc;

	double A[] = { 9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
	double B[] = { 26.7, 75, 1.5, 42.5, 210, 3.8, 254};
	double C[] = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};

	while (tc--)
	{
		vector<int> arr(7);
		for (int i = 0; i < 7; i++) cin >> arr[i];

		int ans = 0;
		for (int w : {0, 3, 6})
			ans += A[w] * pow((B[w] - (double)arr[w]), C[w]);
		for (int w : {1, 2, 4, 5})
			ans += A[w] * pow(((double)arr[w] - B[w]), C[w]);
		
		cout << ans << "\n";

	}
	return 0;
}