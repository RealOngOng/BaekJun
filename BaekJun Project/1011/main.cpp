#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;

int main() {

	int count = 0, add = 1;

	for (ll i = 1; i < INT_MAX; ) {

		arr.push_back(i);

		i += add;

		count++;
		if (count == 2) count = 0, add++;

	}

	int t; scanf("%d", &t);

	while (t--) {

		int a, b; scanf("%d %d", &a, &b);

		ll sub = b - a;

		int idx = upper_bound(arr.begin(), arr.end(), sub) - arr.begin();

		printf("%d\n", idx);

	}

	return 0;

}