#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;

ll seg[4 * 1000000];

void Update(int num, int pos, int start, int end, ll diff) {

	if (pos < start || pos > end) return;
	
	seg[num] += diff;

	if (start == end) return;

	Update(2 * num, pos, start, (start + end) / 2, diff);
	Update(2 * num + 1, pos, (start + end) / 2 + 1, end, diff);

}

ll sum(int num, int l, int r, int start, int end) {

	if (r < start || l > end) return 0;
	if (l <= start && end <= r) return seg[num];

	return sum(2 * num, l, r, start, (start + end) / 2)
		+ sum(2 * num + 1, l, r, (start + end) / 2 + 1, end);

}

int main() {

	ll n, m; scanf("%lld %lld", &n, &m);

	arr.resize(n + 1);

	while (m--) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {

			if (b > c) swap(b, c);

			printf("%lld\n", sum(1, b - 1, c - 1, 0, n - 1));

		}
		else {

			ll diff = c - arr[b - 1];
			arr[b - 1] = c;
			Update(1, b - 1, 0, n - 1, diff);

		}

	}

	return 0;

}