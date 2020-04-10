#include <iostream>
#include <algorithm>
#include <vector>

struct Question
{

	int A = 0, B = 0;

};

std::vector<Question> qs;

int main() {

	int n;
	std::cin >> n;

	qs.resize(n);
	
	for (int i = 0; i < n; i++) {

		int a;
		std::cin >> a;
		qs[i].A = a;

	}
	for (int i = 0; i < n; i++) {

		int b;
		std::cin >> b;
		qs[i].B = b;

	}
		
	std::sort(qs.begin(), qs.end(),
			  [](const Question& q1, const Question& q2) -> bool {

		return q1.B < q2.B;

	});

	int result = 0;

	for (int i = 0; i < n; i += 2) {

		bool isNext = false;

		if (qs[i].B < qs[i + 1].B)
			isNext = true;

		result += ((isNext) ? qs[i].A : qs[i].B);

	}

	std::cout << result << "\n";

	return 0;

}