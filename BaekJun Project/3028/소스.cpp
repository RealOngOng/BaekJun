#include <bits/stdc++.h>

using namespace std;

bool arr[3] = { 1, 0, 0 };

void A() { swap(arr[0], arr[1]); }
void B() { swap(arr[1], arr[2]); }
void C() { swap(arr[0], arr[2]); }

int main() {

	string str; cin >> str;

	for (char c : str) {

		if (c == 'A') A();
		else if (c == 'B') B();
		else if (c == 'C')C();

	}

	for (int i = 0; i < 3; i++)
		if (arr[i]) printf("%d", i + 1);

	return 0;

}