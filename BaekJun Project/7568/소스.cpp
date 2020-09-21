#include <bits/stdc++.h>

using namespace std;

typedef struct Person {

	int x, y;

	bool operator<(const Person& p) {

		return (x < p.x && y < p.y);

	}
	bool operator>(const Person& p) {

		return (x > p.x && y > p.y);

	}

};

int main() {

	int n; scanf("%d", &n);

	vector<Person> vec;

	for (int i = 0; i < n; i++) {

		int a, b; scanf("%d %d", &a, &b);
		vec.push_back({a, b});

	}

	string str;

	for (int i = 0; i < n; i++) {

		int w = 1;

		for (int j = 0; j < n; j++) {

			if (i == j) continue;

			if (vec[i] < vec[j])w++;

		}

		str += to_string(w) + " ";

	}

	cout << str;

	return 0;

}