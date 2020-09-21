#include <bits/stdc++.h>

using namespace std;

double price[5] = { 350.34 , 230.90, 190.55, 125.30, 180.90 };

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		double sum = 0;

		for (int i = 0; i < 5; i++) {

			int a; scanf("%d", &a);
			sum += price[i] * a;

		}

		printf("$%.2lf\n", sum);

	}

	return 0;

}