#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int a; scanf("%d", &a);

		string str;

		while (a) {

			str += (a % 2) + '0';
			a /= 2;

		}

		vector<int> vec;

		for (int i = 0; i < str.length(); i++)
			if(str[i] == '1')vec.push_back(i);

		for (int i : vec)
			printf("%d ", i);

		printf("\n");

	}

	return 0;

}