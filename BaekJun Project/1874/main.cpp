#include <bits/stdc++.h>

using namespace std;

int main() {

	//�Է¹��� �迭
	vector<int> vec;

	//����
	stack<int> input, stk;

	//n�� �Է� �޴� ��
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	//�Է¹��� �迭�� �Ųٷ�
	reverse(vec.begin(), vec.end());
	//input stack �־�α�
	for (int i : vec) input.push(i);

	string result;

	int num = 1, check = 0;

	//n��ŭ ���ƾ� �ȴ�
	while (!input.empty()) {

		//stack.size() > 0�̻��϶� NO�� �Ǻ�
		if (num > n) {

			printf("NO\n");
			return 0;
			
		}

		//������ ���ÿ� �ֱ�
		stk.push(num);

		//��� ���ڿ�
		result += "+\n";

		//!stk.empty() = stk�� ������� ������
		//!input.empty() = input�� ������� ������
		//stk.top() == input.top() / input.top() ���� ����ؾߵ� ��
		while (!stk.empty() && !input.empty() && stk.top() == input.top())
			result += "-\n" , stk.pop(), input.pop();

		num++;

	}

	//�� ���
	cout << result;

	return 0;

}