#include <bits/stdc++.h>

using namespace std;

deque<int> trans(string str) {

	deque<int> ans;
	string top;

	for (int i = 1; i < str.length() - 1; i++) {

		if (str[i] == ',') {

			ans.push_back(atoi(top.c_str()));
			top = "";

		}
		else
			top += str[i];

	}

	if(top != "")
		ans.push_back(atoi(top.c_str()));

	return ans;

}

string to_vec(deque<int>& dq) {

	if (dq.size() == 0) 
		return "[]";

	string result;
	result += '[';

	result += to_string(dq.front());
	dq.pop_front();

	while (!dq.empty()) {

		result += "," + to_string(dq.front());
		dq.pop_front();

	}

	result += ']';

	return result;

}

int main() {

	int tc; cin >> tc;

	while (tc--) {

		string cmd; cin >> cmd;
		int n; cin >> n;
		string str; cin >> str;
		
		deque<int> arr = trans(str);

		bool flag = false;
		bool rev = false;

		for (char c : cmd) {

			if (c == 'R') rev = !rev;
			else {

				if (arr.size() == 0) {

					flag = true;
					break;

				}

				if (!rev) arr.pop_front();
				else arr.pop_back();

			}

		}

		if (flag) cout << "error\n";
		else {

			if (rev) reverse(arr.begin(), arr.end());
			cout << to_vec(arr) << "\n";

		}

	}

	return 0;

}