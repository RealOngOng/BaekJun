#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<pi> arr;

int main() {

	int n, m; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a); arr.push_back({a, i});
	}

	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {

		int a; scanf("%d", &a);

		int idx = lower_bound(arr.begin(), arr.end(), make_pair(a, 0)) - arr.begin();

		if (idx >= arr.size()) printf("0\n");
		else printf("%d\n", (a == arr[idx].first));

	}

	return 0;

}