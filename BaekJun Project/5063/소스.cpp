#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);
	
	while (t--) {

		int r, e, c; 
		scanf("%d %d %d", &r, &e, &c);

		e -= c;

		if (r == e) printf("does not matter\n");
		else if (r < e) printf("advertise\n");
		else printf("do not advertise\n");

	}

	return 0;

}