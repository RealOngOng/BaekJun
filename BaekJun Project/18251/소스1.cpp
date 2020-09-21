#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr, area;

void SetArea(int num, int d, int start, int end) {

	if (end < d) return;

	SetArea(2 * num, d + 1, start, end);
	if(start <= d) area.push_back(arr[num]);
	SetArea(2 * num + 1, d + 1, start, end);

}

int main() {

	int n; scanf("%d", &n);

	arr.resize(n + 1);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	int h = log2(n + 1);

	ll ans = -1e10;

	for (int i = 1; i <= h; i++) {

		for (int j = i; j <= h; j++) {

			area.clear();

			SetArea(1, 1, i, j);

			ll dp = -1e10;

			for (int w = 0; w < area.size(); w++) {

				dp = max(area[w], dp + area[w]);
				ans = max(ans, dp);

			}

		}

	}

	printf("%lld", ans);

	return 0;

}