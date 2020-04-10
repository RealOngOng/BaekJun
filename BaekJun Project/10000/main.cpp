#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

typedef long long ll;

typedef struct Vert {

	bool isLeft;
	ll left, right, radius;

	inline int getX() const { return (isLeft) ? left : right; }

	void debug() {

		std::cout << ((isLeft) ? "left" : "right") << ", " << getX() << "\n";

	}

};

void PrintStack(std::stack<int> stk) {

	while (!stk.empty()) {

		std::cout << stk.top() << " ";
		stk.pop();

	}

	std::cout << "\n";

}

std::vector<Vert> vt;
std::stack<int> stk;

int main() {

	int n; std::cin >> n;
	for (int i = 0; i < n; i++) {

		ll p, r; std::cin >> p >> r;
		vt.push_back({ true, p - r, p + r, r });
		vt.push_back({ false, p - r, p + r, r });

	}

	std::sort(vt.begin(), vt.end(),
			  [](const Vert& v1, const Vert& v2) -> bool {

			if (v1.getX() != v2.getX()) return (v1.getX() < v2.getX());
			if (v1.isLeft != v2.isLeft) return (v1.isLeft < v2.isLeft);
			if (v1.radius != v2.radius) return (v1.radius > v2.radius);

			return false;

	});

	ll sum = 0;

	int size = vt.size();

	stk.push(0);
	for (int i = 1; i < size; i++) {

		//std::cout << "=====" << i << "=====\n\n";
		//PrintStack(stk);

		//vt[i].debug();

		if (stk.size() > 0) {

			int &t = stk.top();
			if (t == 0 || t == 1)
				t = (vt[i].getX() == vt[i - 1].getX()) ? 1 : 2;

		}

		//PrintStack(stk);

		if (vt[i].isLeft)stk.push(0);
		else {

			sum += (stk.top() == 1);
			stk.pop();

		}

		//PrintStack(stk);
		//std::cout << "\n=========\n\n";

	}

	std::cout << n + sum + 1 << "\n";

	return 0;

}