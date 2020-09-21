#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	int left = -1, right = -1;
};

int main() {

	int tc; cin >> tc;
	while (tc--) {

		int n; cin >> n;
		vector<int> preorder(n + 1), inorder(n + 1);
		for (int i = 1; i <= n; i++) cin >> preorder[i];
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			inorder[a] = i;
		}

		vector<Node> V(n + 1);

		int idx = 1;
		function<void(int, int)> solve = [&](int s, int e) -> void {

			if (s >= e) return;

			int u = preorder[idx];
			int mid = inorder[u];
			
			//왼쪽 구간이 포함될때
			if (mid - 1 >= s) {
				V[u].left = preorder[++idx];
				solve(s, mid - 1);
			}

			//오른쪽 구간이 포함될 때
			if (mid + 1 <= e) {
				V[u].right = preorder[++idx];
				solve(mid + 1, e);
			}

		};

		solve(1, n);

		function<void(int)> postorder = [&](int x) -> void {
			if (V[x].left != -1) postorder(V[x].left);
			if (V[x].right != -1) postorder(V[x].right);
			cout << x << " ";
		};

		postorder(preorder[1]);

		cout << "\n";

	}

	return 0;

}