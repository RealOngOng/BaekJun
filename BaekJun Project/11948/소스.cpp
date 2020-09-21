#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> vec;
	for (int i = 0; i < 4; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	sort(vec.begin(), vec.end(), greater<int>());

	int e, f; scanf("%d %d", &e, &f);

	printf("%d", vec[0] + vec[1] + vec[2] + max(e, f));

	return 0;
	
}