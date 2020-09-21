#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> A;

	int a = 0, b = 0;

	int win = 0; //0 ¾Æ¹«µµ ¾Æ´Ô, A : 1, B : 2

	for (int i = 0; i < 10; i++) {

		int t; scanf("%d", &t);
		A.push_back(t);

	}
	for (int i = 0; i < 10; i++) {

		int t; scanf("%d", &t);

		if (A[i] == t) a++, b++;
		else if (A[i] < t) {

			win = 2;
			b += 3;

		}
		else {

			win = 1;
			a += 3;
			
		}

	}
	
	printf("%d %d\n", a, b);

	if (a == b) {

		if (win == 0) printf("D");
		else printf("%c", ((win == 1) ? 'A' : 'B'));

	}
	else if (a < b) printf("B");
	else printf("A");

	return 0;

}