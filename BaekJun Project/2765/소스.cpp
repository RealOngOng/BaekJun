#include <bits/stdc++.h>

using namespace std;

int main() {

	double r, p, t;

	int idx = 0;

	while (true) {

		idx++;

		scanf("%lf %lf %lf", &r, &p, &t);

		if (p == 0) return 0;

		double m = r * p * 3.1415926535 / 63360;

		printf("Trip #%d: %.2lf %.2lf\n", idx, m, m / t * 3600);

	}

	return 0;

}