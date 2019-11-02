#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {

	char line[101];

	cin.getline(line, 101);

	int length = strlen(line);

	cout << line[0];
	for (int i = 0; i < length; i++) if (line[i] == '-') cout << line[i];

	return 0;

}