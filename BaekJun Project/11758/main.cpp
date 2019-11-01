#include <iostream>
#include <utility>
#include <string>

using namespace std;

#define NUM 3

typedef pair<int, int> Vector2;

Vector2 vertex[NUM];

int main() {

	for (int i = 0; i < NUM; i++) cin >> vertex[i].first >> vertex[i].second;

	int area = vertex[0].first * vertex[1].second + vertex[1].first * vertex[2].second
		+ vertex[2].first * vertex[0].second - vertex[0].first * vertex[2].second
		- vertex[1].first * vertex[0].second - vertex[2].first * vertex[1].second;

	string result = "0";

	if (area > 0) result = "1";
	else if (area < 0) result = "-1";

	cout << result << "\n";

	return 0;

}

