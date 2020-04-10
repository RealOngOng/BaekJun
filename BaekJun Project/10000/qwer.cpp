#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct event {
	bool otvaram;
	int left, right, radius;

	event(bool otvaram, int left, int right, int radius) :
		otvaram(otvaram), left(left), right(right), radius(radius) { }

	inline int x() const { return otvaram ? left : right; }

	void debug() const {
		 printf("%s r:%d  %3d : %3d x pos : %3d\n", otvaram ? "otv" :"zat", radius, left, right, x());
	}

	bool operator< (const event &rhs) const {

		if (x() != rhs.x()) return x() < rhs.x();
		if (otvaram != rhs.otvaram) return otvaram < rhs.otvaram;
		if (radius != rhs.radius) return radius > rhs.radius;

		return false;
	}
};

int N;
vector<event> evts;

void load() {

	scanf_s("%d", &N);

	for (int j = 0; j < N; ++j) {

		int c, r;
		scanf_s("%d%d", &c, &r);
		evts.push_back(event(true, c - r, c + r, r));
		evts.push_back(event(false, c - r, c + r, r));

	}

}

void PrintStack(std::stack<int> stk) {

	while (!stk.empty()) {

		std::cout << stk.top() << " ";
		stk.pop();

	}

	std::cout << "\n";

}

#define INIT 0
#define KONT 1
#define DISKONT 2

int solve() {

	sort(evts.begin(), evts.end()); // 점의 x 좌표를 기준으로 정렬, radius가 큰 수록 우선 순위
	int sol = 0;
	stack<int> S;

	for (size_t j = 0; j < evts.size(); ++j) {

		event &e = evts[j];

		//e.debug();

		//std::cout << "=====" << j << "=====\n\n";
		//PrintStack(S);

		//스택 사이즈가 1 이상 일때
		if (S.size()) {

			int &parent_state = S.top();
			if (parent_state == INIT || parent_state == KONT) {
				parent_state = (e.x() == evts[j - 1].x()) ? KONT : DISKONT;
			}

		}

		//PrintStack(S);

		if (e.otvaram) {
			S.push(INIT);
		}
		else {

			sol += (S.top() == KONT);

			S.pop();

		}

		//PrintStack(S);

		//std::cout << "\n=========\n\n";

	}
	return sol + N + 1;
}

int main() {

	load();
	printf("%d\n", solve());

	return 0;

}
