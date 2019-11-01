#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string addBigNum(string _s1, string _s2) {

	string result = "";

	int order = 0;

	int s1_size = _s1.size() - 1,
		s2_size = _s2.size() - 1;

	int up = 0;

	while (s1_size >= order || s2_size >= order) {

		int s1_char = 0, s2_char = 0;

		if (s1_size >= order) { s1_char = _s1[s1_size - order] - '0'; }
		if (s2_size >= order) { s2_char = _s2[s2_size - order] - '0'; }

		result.append(to_string((s1_char + s2_char) % 10 + up));

		up = (s1_char + s2_char > 9) ? 1 : 0;

		order++;

	}

	reverse(result.begin(), result.end());

	return result;

}

int main() {

	int a, b;
	cin >> a >> b;

	cout << addBigNum("0", to_string(pow(a, b)));

	return 0;

}