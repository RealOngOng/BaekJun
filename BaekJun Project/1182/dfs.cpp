#include <bits/stdc++.h>

using namespace std;

int n, s, cnt, csum;
int arr[21];

void dfs(int cur) {

	if (n == cur) return;
	
	if (csum + arr[cur] == s) cnt++;

	dfs(cur + 1);
	csum += arr[cur];

	dfs(cur + 1);
	csum -= arr[cur];

}

int main() {

	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	dfs(0);

	printf("%d\n", cnt);

	return 0;

}