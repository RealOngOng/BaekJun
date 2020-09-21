#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int sumW[1000100];
int sumH[1000100];

int main() {

	int n; cin >> n;

	vector<pi> arr(n + 1);
	for (int i = 0; i < n; i++) {

		int x, y; cin >> x >> y;

		x += 500000;
		y += 500000;

		arr[i] = { x, y };

	}

	arr[n] = arr[0];
	for (int i = 0; i < n; i++) {

		pi now = arr[i];
		pi next = arr[i + 1];

		if (now.first != next.first) {

			if (now.first > next.first) swap(now.first, next.first);
			for (int i = now.first + 1; i <= next.first; i++) sumW[i]++;

		}

		if (now.second != next.second) {

			if (now.second > next.second) swap(now.second, next.second);
			for (int i = now.second + 1; i <= next.second; i++) sumH[i]++;

		}

	}

	int ans = 0;
	ans = max(ans, *max_element(sumW, sumW + 1000100));
	ans = max(ans, *max_element(sumH, sumH + 1000100));

	cout << ans;

	return 0;

}