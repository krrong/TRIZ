#include <iostream>
#define MAX 1000000
using namespace std;

int t;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}

	return GCD(b, a % b);
}

// a-gcd, b-gcd�� �ִ� ������� gcd�� ��ġ�ϴ��� üũ
bool GCDcheck(int a, int b, int gcd) {

	if (GCD(a, gcd) != gcd) return false;
	if (GCD(b, gcd) != gcd) return false;
	return true;
}

// ���� üũ
bool check(int a, int b) {
	if (a > MAX || b > MAX || a <= 1 || b <= 1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int A, B, x, y;
		cin >> A >> B >> x >> y;
		int diff = abs(A - B);
		int expense1 = 0;
		int expense2 = 0;

		// ���� �ø��鼭
		int a = A;
		int b = B;

		while (GCDcheck(a, b, diff) == false) {
			// ����üũ
			if (check(a, b) == false) {
				break;
			}
			a++; b++;
			expense1 = expense1 + x;
		}

		// �Ʒ��� �����鼭
		int aa = A;
		int bb = B;

		while (GCDcheck(aa, bb, diff) == false) {
			// ����üũ
			if (check(aa, bb) == false) {
				break;
			}
			aa--; bb--;
			expense2 = expense2 + y;
		}

		if (GCDcheck(a, b, diff) && GCDcheck(aa, bb, diff)) {
			cout << diff << " " << min(expense1, expense2) << '\n';
		}
		else if (GCDcheck(a, b, diff) == true && GCDcheck(aa, bb, diff) == false) {
			cout << diff << " " << expense1 << '\n';
		}
		else if (GCDcheck(a, b, diff) == false && GCDcheck(aa, bb, diff) == true) {
			cout << diff << " " << expense2 << '\n';
		}
	}


	return 0;
}


// 14 6 3 2
// 8 6
//
// �ݷ�
// 33 41 2 3
// output : 8 75
// answer : 8 3
// 
// �ݷ�
// 6 2 1 1
// output : ���ѷ���
// answer : 4 2
//
// �ݷ�
// 12 5 4 1
// output : 7 4
// answer : 7 8
//
// 7 8 2 1
// 1 0