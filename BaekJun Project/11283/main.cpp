#include <bits/stdc++.h>
#include <locale>

using namespace std;

int main() {

	setlocale(LC_ALL, "korean");

	wchar_t wc[10];
	wscanf(L"%s", wc);

	printf("%d\n", wc[0] - 44031);

	return 0;

}