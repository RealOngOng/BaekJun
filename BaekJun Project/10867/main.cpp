#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		arr.push_back(a);

	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i : arr) printf("%d ", i);

}