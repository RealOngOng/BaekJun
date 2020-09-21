#include <bits/stdc++.h>

using namespace std;

int main() {

	string str; cin >> str;

	if (str.length() == 2) printf("%d", (str[0] - '0' + str[1] - '0'));
	else if (str.length() == 3) {

		if (str[1] == '0') printf("%d", 10 + (str[2] - '0'));
		else if (str[2] == '0') printf("%d", (str[0] - '0') + 10);

	}
	else if (str.length() == 4) printf("20");

	return 0;

}