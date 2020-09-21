#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll dst[100001], lit[100001], sum[100001];

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%lld", &dst[i]);
	for (int i = 0; i < n; i++) scanf("%lld", &lit[i]);

	sum[0] = dst[0] * lit[0];
	ll result = lit[0];

	for (int i = 1; i < n; i++) {

		if (lit[i] < result)
			result = lit[i];

		sum[i] = sum[i - 1] + result * dst[i];

	}

	printf("%lld\n", sum[n - 1]);

	return 0;

}