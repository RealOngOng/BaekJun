#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> vec;
	for (int i = 0; i < 4; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	sort(vec.begin(), vec.end());

	printf("%d", abs(vec[0] + vec[3] - vec[1] - vec[2]));

	return 0;

}