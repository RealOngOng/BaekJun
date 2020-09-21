#include <bits/stdc++.h>
 
using namespace std;

int main() {

	int n; scanf("%d", &n);

	double a = 1;

	for (int i = 1; i <= n; i++) a = a / 2;

	printf("%.*f", n, a);

	return 0;

}
