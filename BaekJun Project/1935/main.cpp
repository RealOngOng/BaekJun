#include <bits/stdc++.h>

using namespace std;

double arr[30];

double GetNum(char c) { return (arr[c - 65]); }

bool isText(char c) { return ('A' <= c && c <= 'Z'); }
bool isOperator(char c) { return (c == '*' || c == '+' || c == '-' || c == '/'); }

int main() {

	stack<double> stk;
	
	int n; std::cin >> n;
	string str; std::cin >> str;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	for (char c : str) {

		if (isText(c)) stk.push(GetNum(c));

		if (isOperator(c)) {

			double n1 = 0, n2 = 0;

			n2 = stk.top(), stk.pop();
			n1 = stk.top(), stk.pop();

			switch (c) {

				case '+': stk.push(n1 + n2); break;
				case '-': stk.push(n1 - n2); break;
				case '*': stk.push(n1 * n2); break;
				case '/': stk.push(n1 / n2); break;

			}

		}

	}

	printf("%.2lf", stk.top());

	return 0;

}