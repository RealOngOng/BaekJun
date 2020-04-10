#include <iostream>
#include <utility>
#include <algorithm>

#define MAX 1000001

typedef std::pair<int, int> Point;

Point line[MAX];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n; std::cin >> n;

	int len = 0;

	for (int i = 0; i < n; i++) {

		int start, end;
		std::cin >> start >> end;

		line[i] = { start, end };

	}

	std::sort(line, line + n,
			  [](const Point& p1, const Point& p2) -> bool{
		return (p1.first < p2.first);
	});

	int startLine = line[0].first, endLine = line[0].second;

	for (int i = 1; i < n; i++) {

		Point p = line[i];

		if (endLine >= p.first)
			endLine = std::max(endLine, p.second);
		else {

			len += endLine - startLine;
			startLine = p.first, endLine = p.second;

		}

	}

	len += endLine - startLine;

	std::cout << len << "\n";
	
	return 0;

}