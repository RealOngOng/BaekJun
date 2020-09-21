#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define MOD 1000000007

typedef long long ll;

std::vector<ll> arr, seg;

void SetTree(int n, int start, int end) {

	if (start == end) {

		seg[n] = arr[start];
		return;

	}

	int mid = (start + end) >> 1;

	SetTree(2 * n, start, mid),
	SetTree(2 * n + 1, mid + 1, end);

	seg[n] = (seg[2 * n] * seg[2 * n + 1]) % MOD;

}

ll multiply(int n, int start, int end, int left, int right) {

	if (left > end || start > right) return 1;

	if (left <= start && end <= right) return seg[n] % MOD;

	int mid = (start + end) >> 1;

	ll m1 = multiply(2 * n, start, mid, left, right),
		m2 = multiply(2 * n + 1, mid + 1, end, left, right);

	return (m1 * m2) % MOD;

}

void Update(int n, int start, int end, int idx, ll diff) {

	if (start == end) {

		seg[n] = diff;
		return;

	}

	int mid = (start + end) >> 1;

	if (start <= idx && idx <= mid)
		Update(2 * n, start, mid, idx, diff);
	else
		Update(2 * n + 1, mid + 1, end, idx, diff);
	
	seg[n] = (seg[2 * n] * seg[2 * n + 1]) % MOD;

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n, m, k;
	std::cin >> n >> m >> k;

	int h = (int)std::ceil(std::log2(n));
	int treesize = (1 << (h + 1));

	arr.resize(n), seg.resize(treesize);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	SetTree(1, 0, n - 1);

	m += k;

	while (m--) {

		ll a, b, c; std::cin >> a >> b >> c;

		if (a == 1)
			Update(1, 0, n - 1, b - 1, c);
		else
			std::cout << multiply(1, 0, n - 1, b - 1, c - 1) % MOD << "\n";

	}

	return 0;

}