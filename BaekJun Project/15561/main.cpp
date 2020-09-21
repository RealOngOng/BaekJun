#include <iostream>
#include <algorithm>

#define MAX 1000001

typedef long long ll;

ll arr[MAX], seg[4 * MAX + 1];

ll SetTree(int n, int start, int end) {

	if (start == end) return seg[n] = arr[start];

	return
		seg[n] =
		SetTree(2 * n, start, (start + end) / 2) +
		SetTree(2 * n + 1, (start + end) / 2 + 1, end);

}

ll Sum(int n, int start, int end, int left, int right) {

	if (left > end || start > right) return 0;

	if (left <= start && end <= right) return seg[n];

	return
		Sum(2 * n, start, (start + end) / 2, left, right) +
		Sum(2 * n + 1, (start + end) / 2 + 1, end, left, right);

}

void Update(int n, int start, int end, int idx, ll diff) {

	if (idx < start || end < idx) return;

	seg[n] += +diff;

	if (start != end) {

		Update(2 * n, start, (start + end) / 2, idx, diff);
		Update(2 * n + 1, (start + end) / 2 + 1, end, idx, diff);

	}

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n, q, u, v;
	std::cin >> n >> q >> u >> v;

	for (int i = 0; i < n; i++) {

		std::cin >> arr[i];

		arr[i] = u * arr[i] + v;

	}

	SetTree(1, 0, n - 1);

	while (q--) {

		ll a, b, c; std::cin >> a >> b >> c;

		if (a == 1) {

			b--;

			ll diff = c - arr[b];
			arr[b] = c;

			Update(1, 0, n - 1, b, diff);

		}
		else {

			std::cout << u * Sum(1, 0, n - 1, b - 1, c - 1) + v * (c- b) << "\n";

		}

	}

	return 0;

}