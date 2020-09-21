#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b; scanf("%d %d", &a, &b);

	if (a == 2 && b == 18) printf("Special");
	else if (a == 2) printf("%s", (b < 18) ? "Before" : "After");
	else if (a < 2) printf("Before");
	else printf("After");

	return 0;

}