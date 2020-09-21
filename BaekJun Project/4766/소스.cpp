#include <bits/stdc++.h> 

using namespace std;

int main() {

	double prev; scanf("%lf", &prev);

	while (true) {

		double now; scanf("%lf", &now);

		if (now == 999) break;

		printf("%.2lf\n", now - prev);

		prev = now;

	}

	return 0;

}