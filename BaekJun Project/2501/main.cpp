#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k; scanf("%d %d", &n, &k);

	vector<int> vec;

	for (int i = 1; i <= n; i++)
		if (n % i == 0) vec.push_back(i);

	k--;

	if (vec.size() <= k) printf("0");
	else printf("%d", vec[k]);

	return 0;

}