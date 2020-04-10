#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main() {

	string line;
	stack<char> text;

	while (true) {

		bool isFlag = false;

		getline(cin, line);

		while (!text.empty()) text.pop();

		if (line == ".") break;

		for (int i = 0; i < line.length(); i++) {

			if (line[i] == '[' || line[i] == '(') text.push(line[i]);

			else if (line[i] == ']')
				if (!text.empty() && text.top() == '[') text.pop();
					else { isFlag = true;  break; }

			else if (line[i] == ')')
				if (!text.empty() && text.top() == '(') text.pop();
					else { isFlag = true;  break; }

		}

		if (isFlag || !text.empty()) cout << "no" << endl;
		else cout << "yes" << endl;

	}

	return 0;

}