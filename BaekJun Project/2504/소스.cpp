#include <bits/stdc++.h>

using namespace std;

int main() {

	stack<string> stk;

	string str; cin >> str;

	for (int i = 0; i < str.length(); i++) {

		string s; s += str[i];

		if (s == "(" || s == "[") stk.push(s);
		else {

			if (stk.empty()) stk.push(s);
			else {

				if (s == ")" && stk.top() == "(") stk.pop();
				if (s == "]" && stk.top() == "[") stk.pop();

			}

		}

	}

	if (stk.size() > 0) {

		cout << "0\n";

		return 0;

	}

	while (!stk.empty()) stk.pop();

	for (int i = 0; i < str.length(); i++) {

		string s; s += str[i];

		if (s == "(") stk.push("2"), stk.push("(");
		else if (s == "[") stk.push("3"), stk.push("[");
		else if (s == ")") {

			int w = 0;

			while (stk.top() != "(")
				w += atoi(stk.top().c_str()), stk.pop();

			stk.pop();

			if (w > 0) {

				w *= atoi(stk.top().c_str());
				stk.pop(), stk.push(to_string(w));

			}

		}
		else if (s == "]") {

			int w = 0;

			while (stk.top() != "[")
				w += atoi(stk.top().c_str()), stk.pop();

			stk.pop();

			if (w > 0) {

				w *= atoi(stk.top().c_str());
				stk.pop(), stk.push(to_string(w));

			}

		}

	}

	int result = 0;

	while (!stk.empty())
		result += atoi(stk.top().c_str()), stk.pop();

	cout << result << "\n";

	return 0;

}