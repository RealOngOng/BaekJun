#include <bits/stdc++.h>

using namespace std;

int main() {

	int front; scanf("%d", &front);

	while (true) {

		char oper; scanf(" %c", &oper);

		if (oper == '=') break;

		int num; scanf("%d", &num);

		if (oper == '+') front += num;
		else if (oper == '-') front -= num;
		else if (oper == '*') front *= num;
		else if (oper == '/') front /= num;

	}

	printf("%d", front);

	return 0;

}