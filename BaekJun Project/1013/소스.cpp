#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main()
{
	regex pattern("(100+1+|01)+");

	int tc; cin >> tc;
	while (tc--)
	{
		string str; cin >> str;
		smatch sm;
		if (regex_match(str, sm, pattern))
		{
			if (sm[0].length() == str.length())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}