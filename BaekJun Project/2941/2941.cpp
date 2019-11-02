#include <iostream>
#include <string>

using namespace std;

int main() {

	string line;
	cin >> line;

	string croatia[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

	for (int i = 0; i < 8; i++) {

		int pos = 0;

		while ((pos = line.find(croatia[i])) != string::npos) {

			if(i == 2) line.replace(pos, 3, "1");
			else line.replace(pos, 2, "1");

		}

	}

	cout << line.size();

	return 0;

}