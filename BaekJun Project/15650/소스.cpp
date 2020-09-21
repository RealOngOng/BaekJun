#include <iostream>
#include <vector>

using namespace std;

#define MAX 9

int n, m;

bool visited[MAX];
int arr[MAX];

void view() {

	for (int i = 0; i < n; i++) cout << "list: " << visited[i] << " ";

	cout << endl;

}

void func(int num, int prev) {

	if (num == m) {

		for (int i = 0; i < m; i++) cout << arr[i] << " ";

		cout << "\n";
		return;

	}

	for (int i = prev + 1; i <= n; i++) {

		if (!visited[i - 1]) {

			visited[i - 1] = true;
			arr[num] = i;
			func(num + 1, i);
			visited[i - 1] = false;

		}

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	func(0, 0);

	return 0;

}