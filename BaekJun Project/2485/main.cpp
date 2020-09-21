#include <bits/stdc++.h>

using namespace std;

vector<int> arr, sub;

int gcd(int a, int b) {

	if (b == 0) return a;
	else return gcd(b, a % b);

}

int allGcd(int num, int next) {

	if (next == sub.size()) return num;
	return  allGcd(gcd(num, sub[next]), next + 1);

}

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		arr.push_back(a);

	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++) sub.push_back(arr[i] - arr[i - 1]);

	sort(sub.begin(), sub.end());
	//sub.erase(unique(sub.begin(), sub.end()), sub.end());

	int range = allGcd(sub[0], 1);

	int count = 0;

	for (int i : sub)
		count += i / range - 1;

	printf("%d\n", count);

	return 0;

}