#include <iostream>
#include <algorithm>
#include <math.h>

#define MONSTER 1
#define POSION 2

typedef long long ll;

//type == 1�� ��� ����
//arg1 : ������ ���ݷ�, arg2 : ������ ü��

//type == 2�� ��� Hp ����
//arg1 : ���ݷ� ������, arg2 : ü�� ������

ll n, atk;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> atk;

	ll var = 0, hp = 0;

	for (int i = 0; i < n; i++) {

		ll type, arg1, arg2;
		std::cin >> type >> arg1 >> arg2;

		if (type == MONSTER) {

			ll dmg = (std::ceil((double)arg2 / atk) - 1) * arg1;
			if (dmg > hp) var += dmg - hp, hp = 0;
			else hp -= dmg;

		}
		else {

			atk += arg1;

			hp += arg2;
			hp = std::min(hp, var);

		}

	}

	std::cout << var + 1;

	return 0;

}