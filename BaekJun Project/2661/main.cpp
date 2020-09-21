#include <bits/stdc++.h>

using namespace std;

int n;
int arr[81];

void Print() {

	for (int i = 0; i < n; i++)
		printf("%d", arr[i]);

	printf("\n");

}

bool isGood(int pos) {

	int dst = pos / 2;

	string str;

	for (int i = 0; i <= pos; i++) str += arr[i] + '0';

	for (int i = 1; i <= dst; i++) {

		for (int j = i; j <= pos - i; j++) {

			string a = str.substr(j - i, i),
				b = str.substr(j, i);

			if (a == b) return false;

		}

	}

	return true;

}

void backtrack(int pos) {

	if (!isGood(pos)) return;

	if (pos == n) {

		Print();
		exit(0);

	}

	for (int i = 1; i <= 3; i++) {

		if (i == arr[pos - 1]) continue;

		arr[pos] = i;
		backtrack(pos + 1);

	}

}

int main() {

	scanf("%d", &n);

	arr[0] = 1;
	backtrack(1);

	return 0;

}