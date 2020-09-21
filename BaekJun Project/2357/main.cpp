#include <iostream>
#include <algorithm>

#define MAX 1000001
#define INF 1e9 + 1

typedef long long ll;

ll arr[MAX], min_seg[4 * MAX], max_seg[4 * MAX];

ll minSetTree(int n, int start, int end) {

	if (start == end) return min_seg[n] = arr[start];

	return
		min_seg[n] = std::min(
			minSetTree(2 * n, start, (start + end) / 2),
			minSetTree(2 * n + 1, (start + end) / 2 + 1, end)
		);

}

ll minimum(int n, int start, int end, int left, int right) {

	if (left > end || start > right) return INF;

	if (left <= start && end <= right) return min_seg[n];

	ll m1 = minimum(2 * n, start, (start + end) / 2, left, right),
		m2 = minimum(2 * n + 1, (start + end) / 2 + 1, end, left, right);

	return std::min(m1, m2);

}

ll maxSetTree(int n, int start, int end) {

	if (start == end) return max_seg[n] = arr[start];

	return
		max_seg[n] = std::max(
			maxSetTree(2 * n, start, (start + end) / 2),
			maxSetTree(2 * n + 1, (start + end) / 2 + 1, end)
		);

}

ll maximum(int n, int start, int end, int left, int right) {

	if (left > end || start > right) return -INF;

	if (left <= start && end <= right) return max_seg[n];

	ll m1 = maximum(2 * n, start, (start + end) / 2, left, right),
		m2 = maximum(2 * n + 1, (start + end) / 2 + 1, end, left, right);

	return std::max(m1, m2);

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	minSetTree(1, 0, n - 1);
	maxSetTree(1, 0, n - 1);

	while (m--) {

		ll a, b; std::cin >> a >> b;

		std::cout << minimum(1, 0, n - 1, a - 1, b - 1) << " " 
			<< maximum(1, 0, n - 1, a - 1, b - 1) << "\n";

	}

	return 0;

}