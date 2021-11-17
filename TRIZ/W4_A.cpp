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

// a-gcd, b-gcd의 최대 공약수가 gcd로 일치하는지 체크
bool GCDcheck(int a, int b, int gcd) {

	if (GCD(a, gcd) != gcd) return false;
	if (GCD(b, gcd) != gcd) return false;
	return true;
}

// 범위 체크
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

		// 위로 올리면서
		int a = A;
		int b = B;

		while (GCDcheck(a, b, diff) == false) {
			// 범위체크
			if (check(a, b) == false) {
				break;
			}
			a++; b++;
			expense1 = expense1 + x;
		}

		// 아래로 내리면서
		int aa = A;
		int bb = B;

		while (GCDcheck(aa, bb, diff) == false) {
			// 범위체크
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
// 반례
// 33 41 2 3
// output : 8 75
// answer : 8 3
// 
// 반례
// 6 2 1 1
// output : 무한루프
// answer : 4 2
//
// 반례
// 12 5 4 1
// output : 7 4
// answer : 7 8
//
// 7 8 2 1
// 1 0