#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

int main() {

	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL); std::cin.tie(NULL);

	while (true) {

		int n; std::cin >> n;

		if (n == 0) break;

		long long *p = new long long[n + 3];
		std::stack<long long> stk;

		for (int i = 1; i <= n; i++)
			std::cin >> p[i];

		p[n + 1] = 0;

		long long len = 0;

		stk.push(0);
		for (int i = 1; i <= n + 1; i++) {

			while (!stk.empty() && p[stk.top()] > p[i]) {

				long long h = p[stk.top()];

				stk.pop();

				long long w = i - stk.top() - 1;

				len = std::max(len, (long long)(w * h));

			}

			stk.push(i);

		}

		std::cout << len << "\n";

	}

	return 0;

}