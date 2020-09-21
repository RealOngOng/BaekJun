#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {
	int x, y;
};

int main() {

	string str; cin >> str;

	vector<vector<char>> txt(5, vector<char>(str.length() * 4 + 1, '.'));
	
	function<void(Vector2, char, char)> solve = [&](Vector2 pos, char a, char t) -> void {
		txt[pos.x + 2][pos.y] = txt[pos.x + 1][pos.y + 1] = txt[pos.x + 3][pos.y + 1]
			= txt[pos.x][pos.y + 2] = txt[pos.x + 4][pos.y + 2] = txt[pos.x + 1][pos.y + 3]
			= txt[pos.x + 3][pos.y + 3] = txt[pos.x + 2][pos.y + 4] = a;
		txt[pos.x + 2][pos.y + 2] = t;	
	};

	for (int i = 0; i < str.length(); i++) {

		if ((i + 1) % 3 == 0) continue;
		solve({0, i * 4}, '#', str[i]);

	}

	for (int i = 2; i < str.length(); i += 3) 
		solve({ 0, i * 4 }, '*', str[i]);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < txt[i].size(); j++)
			cout << txt[i][j];
		cout << "\n";
	}

	return 0;

}