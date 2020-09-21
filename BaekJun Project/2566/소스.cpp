#include <bits/stdc++.h>

using namespace std;

int main() {

	int x = 0, y = 0, m = 0;

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {

			int a; scanf("%d", &a);
			
			if (m < a) {

				x = i, y = j;
				m = a;

			}		

		}

	}

	printf("%d\n%d %d", m, x + 1, y + 1);

	return 0;

}