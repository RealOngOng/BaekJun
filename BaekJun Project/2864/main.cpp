#include <bits/stdc++.h>

using namespace std;

string replaceAll(string str, string from, string to) {

	string temp = string(str);

	size_t pos = 0;

	while ((pos = temp.find(from)) != string::npos) {

		temp.replace(pos, from.length(), to);
		pos += to.length();

	}

	return temp;

}

int main() {

	string str1, str2; cin >> str1 >> str2;

	cout << (atoi(replaceAll(str1, "6", "5").c_str()) + atoi(replaceAll(str2, "6", "5").c_str()))
		<< " " 
		<< (atoi(replaceAll(str1, "5", "6").c_str()) + atoi(replaceAll(str2, "5", "6").c_str())) << "\n";

	return 0;

}