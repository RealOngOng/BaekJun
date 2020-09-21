#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> vec;

	for (int i = 0; i < 3; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	int m = 1e9, idx = 0, sum = 0;

	for (int i = 0; i < 3; i++) {

		if (m > vec[i]) {

			idx = i;
			m = vec[i];

		}

		sum += vec[i];

	}

	string name[3] = {"Soongsil", "Korea", "Hanyang"};

	if (sum >= 100) printf("OK");
	else cout << name[idx];

	return 0;

}