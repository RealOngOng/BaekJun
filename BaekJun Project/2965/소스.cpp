#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b, c; scanf("%d %d %d", &a, &b, &c);

	int cnt = max(b - a, c - b);

	printf("%d", cnt - 1);

	return 0;

}