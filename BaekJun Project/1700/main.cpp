#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<int> vec;
std::vector<int> con;

#define MAX 101

int count[MAX];

int main()
{

	int n, k;
	std::cin >> n >> k;

	int result = 0;

	for (int i = 0; i < k; i++) {

		int c;

		std::cin >> c;

		vec.push_back(c);

	}

	for (int i = 0; i < k; i++) {

		bool isSame = false;

		for (int c : con)
			if (c == vec[i]) {

				isSame = true;
				break;

			}

		if (isSame) continue;

		if (con.size() < n) {

			con.push_back(vec[i]);
			continue;

		}

		int lastidx = -1, noidx = -1;

		std::fill(count, count + MAX, 0);

		//noidx
		for (int j = i + 1; j < k; j++)
			count[vec[j]]++;

		for(int c : con)
			if (count[c] == 0) {

				noidx = c;
				break;

			}

		std::vector<int>::iterator itr;

		if (noidx != -1) {

			itr = std::find(con.begin(), con.end(), noidx);

			con.erase(itr);
			con.push_back(vec[i]);
			result++;

			continue;

		}

		std::fill(count, count + MAX, 0);

		//lastidx

		for (int j = i + 1; j < k; j++) {

			for (int x : con) {

				if (count[x]) continue;

				if (x == vec[j]) {

					lastidx = vec[j];

					count[x] = true;

				}

			}

		}

		if (lastidx != -1) {

			itr = std::find(con.begin(), con.end(), lastidx);

			con.erase(itr);
			con.push_back(vec[i]);

			result++;

		}

	}

	std::cout << result << "\n";

}