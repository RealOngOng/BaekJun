#include <iostream>
#include <stack>
#include <string>
#include <conio.h>

using namespace std;

int main() {

	char line[501];
	string text;
	int size = 0;

	do {

		cin.getline(line, 501);

		if ((text = line) == "END") break;

		for (int i = strlen(line) - 1; i >= 0; i--) cout << line[i];

		cout << "\n";

	} while (true);

	return 0;

}