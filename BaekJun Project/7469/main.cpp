#include <iostream>
#include <algorithm>

#define MAX 1000001
#define INF 1e9 + 1

typedef long long ll;

ll arr[MAX], seg[4 * MAX + 1];

ll SetTree(int n, int start, int end) {

	if (start == end) return seg[n] = arr[start];

	return
		seg[n] = std::min(
			SetTree(2 * n, start, (start + end) / 2),
			SetTree(2 * n + 1, (start + end) / 2 + 1, end)
		);

}

ll minimum(int n, int start, int end, int left, int right) {

	if (left > end || start > right) return INF;

	if (left <= start && end <= right) return seg[n];

	ll m1 = minimum(2 * n, start, (start + end) / 2, left, right),
		m2 = minimum(2 * n + 1, (start + end) / 2 + 1, end, left, right);

	if (m1 == INF) return m2;
	else if (m2 == INF) return m1;
	else return std::min(m1, m2);

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	SetTree(1, 0, n - 1);

	while (m--) {

		ll a, b; std::cin >> a >> b;

		std::cout << minimum(1, 0, n - 1, a - 1, b - 1) << "\n";

	}

	return 0;

}