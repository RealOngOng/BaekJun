#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {

	int n; scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		arr.push_back(a);

	}

	sort(arr.begin(), arr.end(), greater<int>());

	int m = 0;

	for (int i = 0; i < n; i++)
		m = max(m, arr[i] * (i + 1));

	printf("%d\n", m);

	return 0;

}