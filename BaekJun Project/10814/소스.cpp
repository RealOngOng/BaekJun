#include <bits/stdc++.h>

using namespace std;

typedef struct Person {

	int idx, age;
	string name;

	bool operator<(const Person& p) {

		if (age != p.age) return age < p.age;
		else return idx < p.idx;

	}

};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	vector<Person> vec;

	for (int i = 0; i < n; i++) {

		int a; string name;
		cin >> a >> name;

		vec.push_back({i, a, name});

	}

	sort(vec.begin(), vec.end());

	for (Person p : vec)
		cout << p.age << " " << p.name << "\n";

	return 0;

}