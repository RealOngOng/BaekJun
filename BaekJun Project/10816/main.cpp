#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {

	int n, m; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		arr.push_back(a);

	}
	scanf("%d", &m);

	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++) {

		int a; scanf("%d", &a);

		auto low = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
		auto high = lower_bound(arr.begin(), arr.end(), a + 1) - arr.begin();

		printf("%d ", low, high, high - low);

	}

}