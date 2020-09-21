#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pd;

int main() {

	vector<pd> vec;

	double a, b; 
	scanf("%lf %lf", &a, &b);

	vec.push_back({a, b});

	int n; scanf("%d" ,&n);

	while (n--) {

		scanf("%lf %lf", &a, &b);

		vec.push_back({a, b});

	}

	double result = 1e9;

	for (pd d : vec)
		result = min(result, 1000 / d.second * d.first);

	printf("%.2lf", result);

	return 0;

}