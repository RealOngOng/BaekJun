#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str; cin >> str;

	int dec = (int) strtol(str.c_str(), NULL, 16);

	cout << dec << "\n";

	return 0;

}