#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX 123456
#define MONSTER 1
#define POSION 2

typedef long long ll;

//type == 1�� ��� ����
//arg1 : ������ ���ݷ�, arg2 : ������ ü��

//type == 2�� ��� Hp ����
//arg1 : ���ݷ� ������, arg2 : ü�� ������
typedef struct Room {

	ll type, arg1, arg2;

};

Room r[MAX];
int n, atk;

bool simul(ll maxHp) {

	ll hp = maxHp, patk = atk;

	for (int i = 0; i < n; i++) {

		Room room = r[i];

		if (room.type == MONSTER) {


			//�ٸ� ����
			//hp -= (room.arg2 - 1) / patk * room.arg1;

			//if (hp <= 0) return false;

			if(room.arg2 % patk == 0)
				hp -= (std::ceil(room.arg2 / patk) - 1) * room.arg1;
			else
				hp -= (std::ceil(room.arg2 / patk)) * room.arg1;

			if (hp <= 0) return false;

		}
		else {

			patk += room.arg1;
			hp = std::min(hp + room.arg2, maxHp);

		}

	}

	return true;

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	ll low = 1, high = 1e18;

	std::cin >> n >> atk;
	for (int i = 0; i < n; i++) {

		int a, b, c;
		std::cin >> a >> b >> c;

		r[i] = { a, b, c };

	}

	ll result = 0;

	while (low <= high) {

		ll mid = (low + high) * 0.5;

		if (simul(mid)) {

			result = mid;
			high = mid - 1;

		}
		else
			low = mid + 1;

	}

	std::cout << result << "\n";

	return 0;

}