#include <iostream>
using namespace std;

int t;

int check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// 4 -> 4���� y���� ���� �ٸ����� x�� ��� ������ ��
	if (y1 == y2 && y2 == y3 && y3 == y4) {
		if (x3 >= x1 && x3 <= x2 && x4 >= x1 && x4 <= x2) {
			return 4;
		}
		else if (x1 >= x3 && x1 <= x4 && x2 >= x3 && x2 <= x4) {
			return 4;
		}
		// �� �� �̷������� ��ġ�Ǹ� 1��
		else if (x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2) {
			return 1;
		}
		else if (x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) {
			return 1;
		}
		// �� ���� �����ϸ� 2
		else if (x1 == x3 || x1 == x4 || x2 == x3 || x2 == x4) {
			return 2;
		}
		else {
			return 3;
		}
	}
	// 4 -> 4���� x���� ���� �ٸ����� y�� ��� ������ ��
	else if (x1 == x2 && x2 == x3 && x3 == x4) {
		if (y3 >= y1 && y3 <= y2 && y4 >= y1 && y4 <= y2) {
			return 4;
		}
		else if (y1 >= y3 && y1 <= y4 && y2 >= y3 && y2 <= y4) {
			return 4;
		}
		else if (y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2) {
			return 1;
		}
		else if (y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) {
			return 1;
		}
		// �� ���� �����ϸ� 2
		else if (y1 == y3 || y1 == y4 || y2 == y3 || y2 == y4) {
			return 2;
		}
		else {
			return 3;
		}
	}
	// 2 -> x1,x2 ���̿� x3�� �ְ�, y3, y4���̿� y1�� �ְų�
	else if (x3 >= x1 && x3 <= x2 && y1 >= y3 && y1 <= y4) {
		return 2;
	}
	// 2 -> x3,x4 ���̿� x1�� �ְ�, y1, y2���̿� y3�� �ְų�
	else if (x1 >= x3 && x1 <= x4 && y3 >= y1 && y3 <= y2) {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int x1, x2, y1, y2, x3, x4, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		if (x1 > x2) {
			swap(x1, x2);
		}
		if (y1 > y2) {
			swap(y1, y2);
		}
		if (x3 > x4) {
			swap(x3, x4);
		}
		if (y3 > y4) {
			swap(y3, y4);
		}

		cout << check(x1, y1, x2, y2, x3, y3, x4, y4) << '\n';
	}

	return 0;
}

// �ݷ�
// 4 0 8 0
// 3 0 1 0
// output : 3
// answer: 1
// 
// 1 1 2 1
// 1 1 1 2
// 2
//
// 1 1 3 1
// 2 1 2 2
// 2
//
// 1 0 3 0
// 4 0 8 0
// 1
// 
// 1 0 8 0
// 3 0 4 0
// 4
// 
// 1 0 4 0
// 3 0 8 0
// 3
//
// 2 3 2 2
// 2 1 2 0
// 1
// 
// 2 3 2 1
// 2 2 2 0
// 3
// 
// 2 3 2 0
// 2 2 2 1
// 4
//
// �ݷ�
// 1 1 2 1
// 2 1 3 1
// output : 3
// answer : 2