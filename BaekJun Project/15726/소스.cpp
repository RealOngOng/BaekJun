#include <bits/stdc++.h>

using namespace std;

int main() {

	double a, b, c; cin >> a >> b >> c;

	cout << (long long)max(a * b / c, a / b * c);

	return 0;

}