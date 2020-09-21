#include <bits/stdc++.h>

using namespace std;

char carr[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
string iarr[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

int DifferentText(string a, string b) {

	int d = 0;

	for (int i = 0; i < 6; i++) d += (a[i] != b[i]);
		
	return d;

}

int Ok(string bit) {

	int idx = -1;

	for (int j = 0; j < 8; j++) {

		int d = DifferentText(bit, iarr[j]);

		if (d == 0) return j;
		if (d == 1) idx = j;

	}

	return idx;

}

int main() {

	int n; scanf("%d", &n);

	string str; cin >> str;

	string result;

	for (int i = 0; i < n; i++) {

		string bit;

		for (int j = i * 6; j < i * 6 + 6; j++)
			bit += str[j];

		int idx = Ok(bit);

		if (idx == -1) { printf("%d\n", i + 1); return 0; }
		result += carr[idx];

	}

	cout << result << "\n";

	return 0;

}