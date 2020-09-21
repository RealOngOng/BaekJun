#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	int cnt = 0;

	for(int a=1; a <= 500; a++)
		for (int b = 1; b <= 500; b++)
			cnt += (a * a - b * b == n);	

	printf("%d", cnt);

	return 0;

}