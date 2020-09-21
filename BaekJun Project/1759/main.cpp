#include <bits/stdc++.h>

using namespace std;

int n, m;
char word[16], P[16];
bool isVowel[26];

void backtracking(int p, int prev, int vowel, int cont) {

	if (p == n) {

		if (vowel >= 1 && cont >= 2) printf("%s\n", P);
		return;

	}

	for (int i = prev + 1; i < m; i++) {

		P[p] = word[i];
		backtracking(p + 1, i, vowel + isVowel[word[i] - 'a'], cont + !isVowel[word[i] - 'a']);

	}

}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL), cin.tie(NULL);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf(" %c", word + i);

	sort(word, word + m);

	isVowel['a' - 'a'] = isVowel['e' - 'a'] = isVowel['i' - 'a'] =
		isVowel['o' - 'a'] = isVowel['u' - 'a'] = true;

	backtracking(0, -1, 0, 0);

	return 0;

}