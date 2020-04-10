#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

#define MAX 100003

using namespace std;

int N;
long long A[MAX];
long long psum[MAX];
stack<pair<int, int> > stk;

void viewStack() {

	stack<pair<int, int> > temp = stk;

	while (!temp.empty()) {

		pair<int, int> p = temp.top();

		temp.pop();

		std::cout << p.first << ", " << p.second << "\n";

	}

	std::cout << "====================\n";

}

int main() {

	ios_base::sync_with_stdio(false), cin.tie(NULL);

	cin >> N;
	A[N + 1] = 0;

	long long ans = 0;

	for (int i = 1; i <= N + 1; i++) {

		cin >> A[i];

		psum[i] = psum[i - 1] + A[i];

		while (!stk.empty() && stk.top().first > A[i]) {

			auto p = stk.top();

			stk.pop();

			int h = p.first;
			int w = stk.empty() ? 0 : stk.top().second;

			ans = max(ans, (long long)w * h);

			//std::cout << i << " : " << (psum[i - 1] - psum[prv]) * h << "\n";

		}

		stk.push({ A[i], i });

		//std::cout << "\n==========" << i << "==========\n";
		//viewStack();

	}

	cout << ans;

	return 0;
}
