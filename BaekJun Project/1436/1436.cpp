#include <iostream>
#include <string>

using namespace std;

bool isInclude666(int n) {

	string s = to_string(n);

	return (s.find("666") != string::npos);

}

int main() {

	int n;
	cin >> n;

	int i = 666;
	int num = 0;

	while (i) {

		if (isInclude666(i)) {

			num++;

			if (num == n) break;

		}

		i++;

	}

	cout << i;

	return 0;

}