#include <iostream>
#include <algorithm>
#include <math.h>

#define MONSTER 1
#define POSION 2

typedef long long ll;

//type == 1인 경우 몬스터
//arg1 : 몬스터의 공격력, arg2 : 몬스터의 체력

//type == 2인 경우 Hp 물약
//arg1 : 공격력 증가량, arg2 : 체력 증가량

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