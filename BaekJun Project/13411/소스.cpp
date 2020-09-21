#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> pi;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	vector<pi> arr(n);

	for (int i = 0; i < n; i++) {

		double x, y, v; cin >> x >> y >> v;

		double dst = sqrt(x * x + y * y);
		
		arr[i] = { dst / v, i };

	}

	sort(arr.begin(), arr.end());

	for (pi p : arr)
		cout << p.second + 1 << "\n";

	return 0;

}