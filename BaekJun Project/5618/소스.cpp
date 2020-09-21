#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {

	if (a == 0) return b;
	else return gcd(b % a, a);

}

int main() {

	int n; scanf("%d", &n);

	vector<int> vec(3);

	int g = vec[0];

	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]), g = gcd(g, vec[i]);

	vector<int> arr;

	for (int i = 1; i * i <= g; i++)
		if (g % i == 0) {

			printf("%d\n", i);
			if (i * i != g)
				arr.push_back(g / i);

		}

	for (int i = arr.size() - 1; i >= 0; i--)
		printf("%d\n", arr[i]);

	return 0;

}