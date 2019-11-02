#include <iostream>

using namespace std;

#define MAX_NUM 1000001

int Counting[MAX_NUM];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int w;
	for (int i = 0; i < n; i++) {

		cin >> w;
		Counting[w]++;

	}

	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < Counting[i]; j++)
			cout << i << "\n";

	return 0;

}