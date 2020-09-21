#include <bits/stdc++.h>

#define MOD 45678

using namespace std;

typedef long long ll;

int main()
{
	
	int n; scanf("%d", &n);

	ll cnt = 5, num = 7;

	for (int i = 2; i <= n; i++) {

		cnt = (cnt + num) % MOD;
		num = (num + 3) % MOD;

	}

	printf("%d", cnt);

	return 0;

}