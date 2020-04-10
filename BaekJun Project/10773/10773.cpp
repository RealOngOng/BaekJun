#include <iostream>
#include <stack>

using namespace std;

stack<int> list;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int q;
		cin >> q;

		if (q == 0) list.pop();
		else list.push(q);

	}

	int size = list.size(), sum = 0;

	for (int i = 0; i < size; i++) {

		sum += list.top();

		list.pop();

	}

	cout << sum;

	return 0;

}