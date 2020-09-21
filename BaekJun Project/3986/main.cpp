#include <bits/stdc++.h>

using namespace std;

stack<char> stk;

void ClearStack() { while (!stk.empty()) stk.pop(); }

int main() {

	int n; scanf("%d", &n);

	int result = 0;

	while (n--) {

		string str; cin >> str;

		for (char c : str) {

			if (stk.empty()) stk.push(c);
			else {

				if (stk.top() == c) stk.pop();
				else stk.push(c);

			}

		}

		result += stk.empty();

		ClearStack();

	}

	printf("%d", result);

	return 0;

}