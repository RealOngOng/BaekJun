#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		string snum[2];
		int w = 0;

		for (char c : str) {

			if (c == ',') { w++; continue; }

			snum[w] += c;

		}

		int num1 = atoi(snum[0].c_str()), num2 = atoi(snum[1].c_str());

		printf("%d\n", num1 + num2);

	}

	return 0;

}