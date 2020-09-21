#include <bits/stdc++.h>

using namespace std;

int main() {

	//입력받은 배열
	vector<int> vec;

	//스택
	stack<int> input, stk;

	//n과 입력 받는 곳
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	//입력받은 배열을 거꾸로
	reverse(vec.begin(), vec.end());
	//input stack 넣어두기
	for (int i : vec) input.push(i);

	string result;

	int num = 1, check = 0;

	//n만큼 돌아야 된다
	while (!input.empty()) {

		//stack.size() > 0이상일때 NO를 판별
		if (num > n) {

			printf("NO\n");
			return 0;
			
		}

		//무조건 스택에 넣기
		stk.push(num);

		//결과 문자열
		result += "+\n";

		//!stk.empty() = stk이 비어있지 않을때
		//!input.empty() = input이 비어있지 않을때
		//stk.top() == input.top() / input.top() 현재 출력해야될 거
		while (!stk.empty() && !input.empty() && stk.top() == input.top())
			result += "-\n" , stk.pop(), input.pop();

		num++;

	}

	//답 출력
	cout << result;

	return 0;

}