#include <bits/stdc++.h>

using namespace std;

string str;
int n;

int subseq(char c) {

	int cnt = 0;

	for (int i = 0; i < n; i++)
		if (str[i] != c) {

			cnt = max(cnt, i);
			break;

		}

	for (int i = 0; i < n; i++)
		if (str[n - i - 1] != c) {

			cnt = max(cnt, i);
			break;

		}

	return cnt;

}

int main() {

	cin >> n;
	cin >> str;

	int r = 0, b = 0;

	for (char c : str)
		if (c == 'R') r++;
		else b++;

	int cntr = r - subseq('R');
	int cntb = b - subseq('B');

	cout << min(cntr, cntb);

	return 0;

}