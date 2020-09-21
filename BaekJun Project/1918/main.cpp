#include <bits/stdc++.h>

using namespace std;

stack<char> stk;

bool isText(char c) { return ('A' <= c && c <= 'Z'); }
bool isOperator(char c) { return (c == '*' || c == '+' || c == '-' || c == '/'); }
bool isHighOper(char c) { return (c == '*' || c == '/'); }
bool isBraket(char c) { return (c == '(' || c == ')'); }

int main() {

	string str; std::cin >> str;

	for (char c : str) {

		if (isText(c)) {

			cout << c;
			continue;

		}
		
		if (isBraket(c)) {

			if (c == '(') stk.push(c);
			else{

				while (!stk.empty()) {

					if (stk.top() == '(') {

						stk.pop(); break;

					}

					cout << stk.top(), stk.pop();

				}

			}

		}

		if (isOperator(c)) {

			if (isHighOper(c)) {

				while (!stk.empty()) {

					if (stk.top() == '(' || !isHighOper(stk.top())) break;

					cout << stk.top(), stk.pop();

				}

			}
			else {

				while (!stk.empty()) {

					if (stk.top() == '(') break;

					cout << stk.top(), stk.pop();

				}

			}

			stk.push(c);

		}

	}

	while (!stk.empty())
		cout << stk.top(), stk.pop();

	std::cout << "\n";

	return 0;

}